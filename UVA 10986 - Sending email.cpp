#include <bits/stdc++.h>

#define inf 1000000000
#define ii pair<int, int>

using namespace std;

int latency[20010];
int n, m, s, t;
vector< vector<ii> > adj;

void Dijkstra(int s)
{
    for(int i = 0; i<n; i++) latency[i] = inf;
    latency[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push( ii(latency[s], s) );
    ii p;
    int t, u;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        t = p.first; u = p.second;
        if(t > latency[u] ) continue;
        for(int i = 0; i<adj[u].size(); i++){
            if(latency[adj[u][i].first] > latency[u] + adj[u][i].second){
                latency[adj[u][i].first] = latency[u] + adj[u][i].second;
                pq.push( ii(latency[adj[u][i].first], adj[u][i].first) );
            }
        }
    }
}


int main()
{
    int tc;
    scanf("%d", &tc);
    for(int k = 1; k<=tc; k++){
        scanf("%d%d%d%d", &n, &m, &s, &t);
        adj.assign(n, vector<ii>(0));
        int x, y, l;
        for(int i = 0; i<m; i++){
            scanf("%d%d%d", &x, &y, &l);
            adj[x].push_back( ii(y, l) );
            adj[y].push_back( ii(x, l) );
        }

        Dijkstra(s);
        printf("Case #%d: ", k);
        if(latency[t] != inf) printf("%d\n", latency[t]);
        else printf("unreachable\n");
    }
}

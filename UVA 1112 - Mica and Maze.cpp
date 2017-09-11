// Reversed the edges of the graph to be able to use the exit node
// as the source node in Dijkstra's algorithm


#include <bits/stdc++.h>

#define inf 1000000000
#define ii pair<int, int>

using namespace std;

vector< vector<ii> > adj;
int dist[110];
int n,e,t,m;

void Dijkstra(int s)
{
    for(int i = 0; i <= n; i++ ) dist[i] = inf;
    dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(dist[s], s));
    ii p;
    int d, u;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        d = p.first; u = p.second;
        if(d > dist[u]) continue;
        for(int i = 0; i<adj[u].size(); i++){
            if(dist[adj[u][i].first] > dist[u] + adj[u][i].second){
                dist[adj[u][i].first] = dist[u] + adj[u][i].second;
                pq.push( ii( dist[adj[u][i].first], adj[u][i].first ) );
            }
        }
    }
}


int main()
{
    int tc;
    scanf("%d", &tc);
    for(int k = 0; k<tc; k++){
        if(k) printf("\n");
        scanf("%d%d%d%d", &n, &e, &t, &m);
        adj.assign(n+1,vector<ii>(0));
        int a, b, c;

        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &c);
            adj[b].push_back( ii( a, c ) );
        }

        Dijkstra(e);
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(dist[i]<=t) ans++;
        }

        printf("%d\n", ans);
    }
}

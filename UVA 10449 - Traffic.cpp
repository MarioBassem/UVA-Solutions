#include <bits/stdc++.h>
#define ii pair<int, int>
#define inf 1000000000000

using namespace std;

vector< vector<ii> > adj(210);
long long dist[210];
int n, cost[210];
bool reachable[210];

void BellmanFord()
{
    for(int i=2; i<=n; i++) dist[i] = inf;
    dist[1] = 0;
    ii p;
    bool isUpdated = 0;
    for(int i=0; i<n-1; i++){
        isUpdated = 0;
        for(int u=1; u<=n; u++){
            for(int j=0; j<adj[u].size(); j++){
                p = adj[u][j];
                if( dist[p.first] > dist[u] + p.second && dist[u] != inf ){
                    dist[p.first] = dist[u] + p.second;
                    isUpdated = 1;
                }
            }
        }
        if(!isUpdated) break;
    }
    memset(reachable, 0, sizeof reachable);
    queue<int> q;
    for(int u=1; u<=n; u++){
        for(int j=0; j<adj[u].size(); j++){
            p = adj[u][j];
            if(dist[p.first] > dist[u] + p.second && dist[u] != inf ){
                q.push(p.first);
            }
        }
    }
    int t;
    while(!q.empty()){
        t = q.front();
        q.pop();
        if(reachable[t]) continue;
        reachable[t] = 1;
        for(int i=0; i<adj[t].size(); i++)
            q.push( adj[t][i].first );
    }
}

int main()
{
    int tc = 1;
    while(scanf("%d", &n) == 1){
        for(int i=1; i<=n; i++) adj[i].clear();
        for(int i=1; i<=n; i++) scanf("%d", &cost[i] );
        int r;
        scanf("%d", &r);
        int a, b, temp;
        for(int i=0; i<r; i++){
            scanf("%d%d", &a, &b);
            temp = cost[b] - cost[a];
            temp = temp * temp * temp;
            adj[a].push_back( ii(b, temp) );
        }
        int q;
        scanf("%d", &q);
        printf("Set #%d\n",tc++);
        BellmanFord();
        for(int i=0; i<q; i++){
            scanf("%d", &a);
            if(dist[a] < 3 || dist[a] == inf || reachable[a] ) printf("?\n");
            else printf("%lld\n", dist[a]);
        }
    }
}

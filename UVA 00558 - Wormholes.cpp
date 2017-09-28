#include <bits/stdc++.h>
#define ii pair<int, int>
#define inf 1000000000

using namespace std;

vector< vector<ii> > adj;
int dist[1010], n, m;

bool isThereNegativeCycle()
{
    for(int i=1; i<n; i++) dist[i] = inf;
    ii p;
    for(int i=0; i<n-1; i++){
        for(int u=0; u<n; u++){
            for(int j=0; j<adj[u].size(); j++){
                p = adj[u][j];
                if(dist[p.first] > dist[u] + p.second)
                    dist[p.first] = dist[u] + p.second;
            }
        }
    }
    for(int u=0; u<n; u++){
        for(int j=0; j<adj[u].size(); j++){
            p = adj[u][j];
            if(dist[p.first] > dist[u] + p.second)
                return true;
        }
    }
    return false;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d", &n, &m);
        adj.assign(n, vector<ii>(0) );
        int a, b, c;
        for(int i=0; i<m; i++){
            scanf("%d%d%d", &a, &b, &c);
            adj[a].push_back( ii(b, c) );
        }
        if( isThereNegativeCycle() ) printf("possible\n");
        else printf("not possible\n");

    }
}

#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>

int n, s, t, res[110][110], maximumFlow, f;
vector<vi> adj;
vi p;

void augment(int v, int minEdge)
{
    if(v==s){
        f = minEdge;
        return;
    }else if(p[v]!=-1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main()
{
    int network = 1;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        memset(res, 0, sizeof res);
        adj.assign(n+1, vi(0));
        int c;
        scanf("%d%d%d", &s, &t, &c);
        int x, y, z;
        for(int i=0; i<c; i++){
            scanf("%d%d%d", &x, &y, &z);
            adj[x].push_back(y);
            adj[y].push_back(x);
            res[x][y]+=z;
            res[y][x]+=z;
        }
        maximumFlow = 0;
        while(1){
            f = 0;
            vi dist(n+1, inf);
            p.assign(n+1, -1);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int v, u = q.front(); q.pop();
                if(u==t) break;
                for(int i=0; i<adj[u].size(); i++){
                    v = adj[u][i];
                    if(res[u][v] > 0 && dist[v]==inf)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                }
            }
            augment(t, inf);
            if(!f) break;
            maximumFlow += f;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", network++, maximumFlow);
    }
}

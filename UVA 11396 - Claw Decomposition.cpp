#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector< vector<int> >

vii adj;
int vis[310];

bool bfs(int s)
{
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v]){
                vis[v] = 3 - vis[u];
                q.push(v);
            }else if(vis[u] == vis[v]) return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        adj.assign(n+1, vi(0) );
        memset(vis, 0, sizeof vis);
        int a, b;
        while(1){
            scanf("%d%d", &a, &b);
            if(!a && !b) break;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool ch = 1;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                if(!bfs(i)){
                    ch = 0;
                    break;
                }
            }
        }
        if(!ch) printf("NO\n");
        else printf("YES\n");
    }
}

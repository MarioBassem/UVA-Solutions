#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int> >

using namespace std;

vii adj;
bool vis[10010];
stack<int> st;

void dfs(int u)
{
    vis[u] = 1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(!vis[v])
            dfs(v);
    }
    st.push(u);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof vis);
        adj.assign(n+1, vi(0) );
        int a, b;

        for(int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
        }

        for(int i=1; i<=n; i++)
            if(!vis[i])
                dfs(i);

        memset(vis, 0, sizeof vis);
        int cnt = 0;

        while(!st.empty()){
            int u = st.top(); st.pop();
            if(!vis[u]){
                dfs(u);
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }
}

#include <bits/stdc++.h>

using namespace std;

char grid[110][110];
int n, Components;
bool vis[110][110];

void dfs(int i, int j)
{
    vis[i][j] = 1;
    if(j+1 < n && !vis[i][j+1]) dfs(i, j+1);
    if(j && !vis[i][j-1]) dfs(i, j-1);
    if(i+1 < n && !vis[i+1][j]) dfs(i+1, j);
    if(i && !vis[i-1][j]) dfs(i-1, j);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc<=t ; tc++){
        memset(vis, 0, sizeof vis);
        scanf("%d", &n);
        getchar();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%c", &grid[i][j]);
                if(grid[i][j] == '.')
                    vis[i][j] = 1;
            }
            getchar();
        }
        Components = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 'x'){
                    Components++;
                    dfs(i, j);
                }
            }
        }
        printf("Case %d: %d\n", tc, Components);
    }
}

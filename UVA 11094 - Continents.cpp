#include <bits/stdc++.h>

using namespace std;


char grid[25][25];
int n, m, vis[25][25], maxComponent, curComponent;

void dfs(int i, int j)
{
    curComponent++;
    vis[i][j] = 1;
    if(!vis[i][(j+1)%n]) dfs(i, (j+1)%n);
    if(!vis[i][(j-1+n)%n]) dfs(i, (j-1+n)%n);
    if(i+1 < m && !vis[i+1][j]) dfs(i+1, j);
    if(i-1 >= 0 && !vis[i-1][j]) dfs(i-1, j);
}

int main()
{
    while(cin>>m>>n){
        memset(vis, 0, sizeof vis);
        getchar();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                scanf("%c", &grid[i][j]);
            }
            getchar();
        }

        int x, y;
        scanf("%d%d", &x, &y);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                if(grid[i][j] != grid[x][y])
                    vis[i][j] = 1;
        }
        dfs(x, y);

        maxComponent = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    curComponent = 0;
                    dfs(i, j);
                    maxComponent = max(maxComponent, curComponent);
                }
            }
        }
        printf("%d\n", maxComponent);
    }
}

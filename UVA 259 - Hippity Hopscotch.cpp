#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>

int n, k, grid[110][110], dist[110][110], ans;
bool visited[110][110];
stack<ii> st;

void topologicalSort(int i, int j)
{
    visited[i][j] = 1;
    for(int l = 1; l<=k; l++){
        if(i + l < n && !visited[i+l][j] && grid[i][j] > grid[i+l][j])
            topologicalSort(i+l, j);

        if(i - l >= 0 && !visited[i-l][j] && grid[i][j] > grid[i-l][j])
            topologicalSort(i-l, j);

        if(j + l < n && !visited[i][j+l] && grid[i][j] > grid[i][j+l])
            topologicalSort(i, j+l);

        if(j - l >= 0 && !visited[i][j-l] && grid[i][j] > grid[i][j-l])
            topologicalSort(i, j-l);

    }
    st.push( ii(i, j) );
}

void shortestPath()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dist[i][j] = inf;

    dist[0][0] = grid[0][0];
    ans = grid[0][0];
    int i, j;
    while(!st.empty()){
        i = st.top().first;
        j = st.top().second;
        st.pop();
        for(int l=1; l<=k; l++){

            if(i + l < n && grid[i][j] > grid[i+l][j] && dist[i+l][j] > dist[i][j] + grid[i+l][j] ){
                dist[i+l][j] = dist[i][j] + grid[i+l][j];
                ans = min(ans, dist[i+l][j]);
            }

            if(i - l >= 0 && grid[i][j] > grid[i-l][j] && dist[i-l][j] > dist[i][j] + grid[i-l][j]){
                dist[i-l][j] = dist[i][j] + grid[i-l][j];
                ans = min(ans, dist[i-l][j]);
            }

            if(j + l < n && grid[i][j] > grid[i][j+l] && dist[i][j+l] > dist[i][j] + grid[i][j+l]){
                dist[i][j+l] = dist[i][j] + grid[i][j+l];
                ans = min(ans, dist[i][j+l]);
            }

            if(j - l >= 0 && grid[i][j] > grid[i][j-l] && dist[i][j-l] > dist[i][j] + grid[i][j-l]){
                dist[i][j-l] = dist[i][j] + grid[i][j-l];
                ans = min(ans, dist[i][j-l]);
            }

        }
    }
    ans *= -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        memset(visited, 0, sizeof visited);
        scanf("%d%d", &n, &k);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                scanf("%d", &grid[i][j]);
                grid[i][j] *= -1;
            }

        topologicalSort(0, 0);
        shortestPath();
        printf("%d\n", ans);
        if(t) printf("\n");
    }
}

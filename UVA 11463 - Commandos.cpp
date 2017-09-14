// Since each commando can go to any building by him self, then the time needed
// to complete the mission is the time taken by the last commando to arrive.
// 
// This is done by calculating the shortest path between all pairs of buildings
// using Floyd Warshall's algorithm, then calculating the maximum path between 
// the source and the destination through any intermediate building.

#include <bits/stdc++.h>

#define inf 1000000000

int sp[110][110];

void init()
{
    for(int i=0; i<110; i++){
        for(int j=0; j<110; j++)
            if(i == j) sp[i][j] = 0;
            else sp[i][j] = inf;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    int n, r;
    for(int tc=1; tc<=t; tc++){
        scanf("%d%d", &n, &r);
        init();
        int a, b;
        for(int i=0; i<r; i++){
            scanf("%d%d", &a, &b);
            sp[a][b] = 1;
            sp[b][a] = 1;
        }
        int s, d;
        scanf("%d%d", &s, &d);

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(sp[i][j] > sp[i][k] + sp[k][j])
                        sp[i][j] = sp[i][k] + sp[k][j];
                }
            }
        }

        int ans=-1;
        for(int i=0; i<n; i++){
            if(sp[s][i] + sp[i][d] > ans)
                ans = sp[s][i] + sp[i][d];
        }
        printf("Case %d: %d\n", tc, ans);
    }
}

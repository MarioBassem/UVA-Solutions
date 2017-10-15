#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000

int n, in[6], co[10][7];
int ord[6], memo[10][10][10][10][10][10], combo;

int dp(int a, int b, int c, int d, int e, int f)
{
    if(a > ord[0] || b > ord[1] || c > ord[2] || d > ord[3] || e > ord[4] || f > ord[5]) return inf;
    if(a == ord[0] && b == ord[1] && c == ord[2] && d == ord[3] && e == ord[4] && f == ord[5]) return 0;
    
    int &ret = memo[a][b][c][d][e][f];
    if(ret != -1) return ret;
    
    ret = inf;
    int t[6] = {0};
    t[0] = 1;
    for(int i=0; i<n; i++){
        if(i){
            t[i] = 1;
            t[i-1] = 0;
        }
        ret = min(ret, dp(a + t[0], b + t[1], c + t[2], d + t[3], e + t[4], f + t[5]) + in[i]);
    }
    
    for(int i=0; i<combo; i++){
        for(int j=0; j<n; j++)
            t[j] = co[i][j];
        ret = min(ret, dp(a + t[0], b + t[1], c + t[2], d + t[3], e + t[4], f + t[5]) + co[i][6]);
    }
    return ret;

}

int main()
{
    while(scanf("%d", &n) == 1){
        for(int i=0; i<n; i++){
            scanf("%d", &in[i]);
        }
        scanf("%d", &combo);
        for(int i=0; i<combo; i++){
            for(int j=0; j<n; j++)
                scanf("%d", &co[i][j]);
            scanf("%d", &co[i][6]);
        }
        int orders;
        scanf("%d", &orders);
        for(int i=0; i<orders; i++){
            memset(ord, 0, sizeof ord);
            for(int j=0; j<n; j++)
                scanf("%d", &ord[j]);
            memset(memo, -1, sizeof memo);
            printf("%d\n", dp(0, 0, 0, 0, 0, 0));
        }

    }
}

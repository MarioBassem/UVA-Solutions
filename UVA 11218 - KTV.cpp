#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000

int n, memo[(1<<9)], valid[10][10][10];

int dp(int u)
{
//  If all the first 9 bits of u are set ( each person is in a group ), 
//  then this is a possible answer.
    if(u == (1<<9) - 1) return 0;

//  If this state was reached before, return the answer.
    int &ret = memo[u];
    if(ret != -1) return ret;

//  Try all possible combinations left.
    ret = -1000000;
    int temp;
    for(int i=0; i<9; i++){
        if((1<<i) & u) continue;
        for(int j = i + 1; j<9; j++){
            if((1<<j) & u) continue;
            for(int k = j+1; k<9; k++){
                if((1<<k) & u || valid[i][j][k] == -1) continue;
                temp = u | (1<<i) | (1<<j) | (1<<k);
                ret = max(ret, dp(temp) + valid[i][j][k] );
            }
        }
    }
    return ret;
}

int main()
{
    int tc = 1;
    while(1){
        scanf("%d", &n);
        if(!n) return 0;
        memset(valid, -1, sizeof valid);
        memset(memo, -1, sizeof memo);
        int a, b, c, s;
        for(int i=0; i<n; i++){
            scanf("%d%d%d%d", &a, &b, &c, &s);
            a--; b--; c--;
            valid[a][b][c] = s;
        }
        int ans = dp(0);
        if(ans < 0) ans = -1;
        printf("Case %d: %d\n", tc++, ans );
    }
}

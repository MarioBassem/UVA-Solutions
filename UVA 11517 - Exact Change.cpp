#include <bits/stdc++.h>

using namespace std;

int dp[110][20010];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int price;
        scanf("%d", &price);
        int n;
        scanf("%d", &n);
        int input[n];
        for(int i=0; i<n; i++) scanf("%d", &input[i]);
        for(int i=1; i<price + 10000; i++) dp[0][i] = inf;
        dp[0][0] = 0;
        dp[0][input[0]] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<price + 10010; j++){
                if(j - input[i] >= 0) dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-input[i]]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        for(int i=price; i<price + 10010; i++)
            if(dp[n-1][i] < inf){
                printf("%d %d\n", i, dp[n-1][i]);
                break;
            }
    }


}

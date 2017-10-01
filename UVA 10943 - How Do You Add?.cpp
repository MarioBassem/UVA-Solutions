#include <bits/stdc++.h>

using namespace std;

int memo[110][110], n, k, mod = 1000000;

int dp(int rem, int sum)
{
    if(!rem) {
        if(sum == n) return 1;
        return 0;
    }

    int &ret = memo[rem][sum];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<=n; i++){
        if(sum + i <= n){
            ret = (ret + dp(rem - 1, sum + i) ) % mod;
        }
    }
    return ret;
}

int main()
{
    while(1){
        scanf("%d%d", &n, &k);
        if(!n && !k) break;
        memset(memo, -1, sizeof memo);
        int ans = 0;
        for(int i=0; i<=n; i++)
            ans = (ans + dp(k - 1, i) ) % mod;
        printf("%d\n", ans);
    }
}

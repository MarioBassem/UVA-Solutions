#include <bits/stdc++.h>

using namespace std;

int n, k, m;
long long memo[55][55][55];

long long dp(int u, int bar, int width)
{
    if(u == n){
        if(!bar) return 1;
        return 0;
    }
    if(!bar) return 0;

    long long &ret = memo[u][bar][width];
    if(ret != -1) return ret;

    if(width)
        return ret = dp(u+1, bar, width-1) + dp(u+1, bar-1, m-1);

    return ret = dp(u+1, bar-1, m-1);
}



int main()
{
    while(scanf("%d%d%d", &n, &k, &m) == 3){
        memset(memo, -1, sizeof memo);
        printf("%lld\n", dp(0, k, m-1) );
    }
}

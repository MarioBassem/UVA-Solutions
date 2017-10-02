#include <bits/stdc++.h>

using namespace std;

int n, t, p, memo[75][75], temp;

int dp(int u, int sum)
{
    if(sum > t) return 0;
    if(u == n){
        if(sum == t) return 1;
        return 0;
    }

    int &ret = memo[u][sum];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=p; i<=temp; i++){
        ret += dp(u+1, sum + i);
    }
    return ret;
}

int main()
{
    int k;
    scanf("%d", &k);

    while(k--){
        scanf("%d%d%d", &n, &t, &p);
        memset(memo, -1, sizeof memo);
        temp = t - (n-1) * p;
        printf("%d\n", dp(0, 0));
    }

}

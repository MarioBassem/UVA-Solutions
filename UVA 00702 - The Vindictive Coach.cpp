#include <bits/stdc++.h>

using namespace std;

int n, m;
long long memo[22][22][2];
bool vis[22];

long long dp(int taken, int l, int p)
{
    if(taken == n) return 1;

    long long &ret = memo[taken][l][p];
    if(ret != -1) return ret;

    ret = 0;
    if(p){
        for(int i=l+1; i<n; i++){
            if(!vis[i]){
                vis[i] = 1;
                ret += dp(taken + 1, i, 0);
                vis[i] = 0;
            }
        }
    }else{
        for(int i=0; i<l; i++){
            if(!vis[i]){
                vis[i] = 1;
                ret += dp(taken + 1, i, 1);
                vis[i] = 0;
            }
        }
    }
    return ret;

}

int main()
{
    while(scanf("%d%d", &n, &m) == 2){
        if(n <= 2){
            printf("1\n");
            continue;
        }
        memset(memo, -1, sizeof memo);
        memset(vis, 0, sizeof vis);
        m--;
        if(m){
            vis[m] = 1;
            printf("%lld\n", dp(1, m, 0));
        }else{
            vis[0] = vis[2] = vis[1] = 1;
            printf("%lld\n", dp(3, 1, 1));
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

int n, in[20], memo[1<<15];

int dp(int u)
{
    if(u == (1<<n) - 1) return 0;

    int &ret = memo[u];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<n; i++){
        if((1<<i) & u) continue;
        for(int j=i+1; j<n; j++){
            if((1<<j) & u) continue;
            for(int k=j+1; k<n; k++){
                if(!((1<<k) & u) && in[i] + in[j] + in[k] >= 20)
                    ret = max(ret, dp(u | (1<<i) | (1<<j) | (1<<k)) + 1);
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
        for(int i=0; i<n; i++)
            scanf("%d", &in[i]);
        memset(memo, -1, sizeof memo);
        printf("Case %d: %d\n", tc++, dp(0) );
    }
}

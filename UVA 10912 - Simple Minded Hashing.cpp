#include <bits/stdc++.h>

using namespace std;


int l, s, memo[27][26*27/2 + 1][27];

int dp(int u, int sum, int len)
{
    if(!sum && !len) return 1;
    if((!sum && len) || (!len && sum)) return 0;

    int &ret = memo[u][sum][len];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=u+1; i<=26; i++){
        if(sum - i < 0) break;
            ret += dp(i, sum - i, len - 1);

    }

    return ret;
}

int main()
{
    int tc = 1;
    memset(memo, -1, sizeof memo);
    while(1){
        scanf("%d%d", &l, &s);
        if(!l && !s) return 0;
        if(s > 26*27/2 || l > 26){
            printf("Case %d: 0\n", tc++);
            continue;
        }
        printf("Case %d: %d\n", tc++, dp(0, s, l) );
    }

}

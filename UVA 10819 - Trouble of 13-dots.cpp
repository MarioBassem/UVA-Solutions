#include <bits/stdc++.h>

using namespace std;

int pr[110], fav[110];
int m, n, memo[101][10210];

int dp(int u, int sum)
{
    if(sum > m && m < 1800) return -inf;
    if(sum > m + 200) return -inf;
    if(u == n){
        if(sum > m && sum <= 2000 ) return -inf;
        else return 0;
    }

    int &ret = memo[u][sum];
    if(ret != -1) return ret;

    return ret = max(dp(u+1, sum + pr[u]) + fav[u], dp(u+1, sum) );
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(scanf("%d%d", &m, &n) == 2 ){

        if(!n || !m){
            printf("0\n"); continue;
        }

        for(int i=0; i<n; i++)
            scanf("%d%d", &pr[i], &fav[i] );

        memset(memo, -1, sizeof memo);

        printf("%d\n", dp(0, 0) );
    }


}

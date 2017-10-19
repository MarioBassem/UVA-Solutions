#include <bits/stdc++.h>

using namespace std;

#define vii vector<vector<int> >
#define vi vector<int>

int n;
long long memo[1<<16];
vi val;
vector<string> in(16);

long long dp(int u)
{
    if(u == (1<<n) - 1) return 1;
    long long &ret = memo[u];
    if(ret != -1) return ret;
    ret = 0;
    int x, it = 0;
    for(int i=0; i<n; i++){

        if(val[i] && !( (1<<i) & u) ){

            for(int j=0; j<n; j++){
                val[j] += in[i][j] - '0';
            }

            ret += dp(u | (1<<i) );

            for(int j=0; j<n; j++){
                val[j] -= in[i][j] - '0';
            }

        }

    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d", &n);
        string s;
        cin>>s;
        val.assign(n, 0);
        for(int i=0; i<n; i++)
            val[i] = s[i] - '0';

        for(int i=0; i<n ;i++){
            cin>>in[i];
        }

        memset(memo, -1, sizeof memo);
        printf("Case %d: %lld\n", tc, dp(0) );
    }


}

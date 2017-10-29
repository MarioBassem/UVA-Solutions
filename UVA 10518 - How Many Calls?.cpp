#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int, int> >
#define vvi vector< vector<int> >
#define vvl vector< vector<long long> >
#define vvii vector< vector< pair<int, int > > >

ll mod;

vvl multiply(vvl a, vvl b)
{
    vvl ret(2, vl(2) );
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ret[i][j] = 0;
            for(int k=0; k<2; k++)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
        }
    }
    return ret;
}

vvl mat_pow(vvl a, ll e)
{
    if(e == 1) return a;
    vvl ret = mat_pow(a, e / 2);
    ret = multiply(ret, ret);
    if(e % 2){
        vvl temp(2, vl(2, 1) );
        temp[1][1] = 0;
        ret = multiply(ret, temp);
    }
    return ret;
}

int main()
{
    ll n;
    int tc = 1, f[3] = {1, 1, 3};
    while(cin>>n>>mod){
        if(!n && !mod) return 0;
        if(n <= 2){
            printf("Case %d: %lld %d %lld\n", tc++, n, mod, f[n] % mod);
            continue;
        }
        vvl t(2, vl(2, 1) );
        t[1][1] = 0;
        vl c(2, 1);
        vvl b = mat_pow(t, n - 1);

        ll ans = 0;
        for(int i=0; i<2; i++)
            ans = (ans + b[0][i] * c[i] ) % mod;

        ans = ( (ans * 2) % mod - 1 + mod ) % mod;
        printf("Case %d: %lld %d %lld\n", tc++, n, mod, ans);

    }
}

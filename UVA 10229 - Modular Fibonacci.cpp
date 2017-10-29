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

int mod;

vvl multiply(vvl a, vvl b)
{
    vvl ret(2, vl(2) );

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ret[i][j] = 0;
            for(int k=0; k<2; k++){
                ret[i][j] =(ret[i][j] % mod + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return ret;
}

vvl mat_pow(vvl a, int e)
{
    if(e == 1) return a;

    vvl ret = mat_pow(a, e/2);
    ret = multiply(ret, ret);

    if(e % 2 == 1){
        vvl temp(2, vl(2) );
        temp[0][0] = temp[0][1] = temp[1][0] = 1;
        temp[1][1] = 0;
        ret = multiply(ret, temp);
    }

    return ret;
}

int main()
{
    int n, m, f[3] = {0, 1, 1};
    while(cin>>n>>m){
        mod = 1<<m;
        if(n <= 2){
            printf("%d\n", f[n] % mod);
            continue;
        }
        vvl a(2, vl(2) );
        a[0][0] = a[0][1] = a[1][0] = 1;
        a[1][1] = 0;
        vvl b = mat_pow(a, n-2);
        vl temp(2); temp[0] = 1; temp[1] = 1;
        ll ans = 0;
        for(int k=0; k<2; k++){
            ans = (ans % mod + (b[0][k] * temp[k]) % mod) % mod;
        }
        printf("%d\n", ans);

    }



}

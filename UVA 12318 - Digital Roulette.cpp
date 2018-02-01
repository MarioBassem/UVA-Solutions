#include <bits/stdc++.h>
#define EPS 1e-9
#define PI 3.14159265359
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >

typedef long long ll;

using namespace std;

ll mod;
bool vis[10000001];

ll pw(ll u, ll e)
{
    if(e == 1) return u;
    if(!e) return 1;
    ll temp = pw(u, e / 2);
    temp = (temp * temp) % mod;
    if(e % 2) temp = (temp * u) % mod;
    return temp;

}

int main()
{
    int n, m, k, a[11], cnt;
    ll sum;
    while(1){
        scanf("%d%d", &n, &m);
        if(!n && !m) return 0;
        scanf("%d", &k);
        for(int i=0; i<=k; i++) scanf("%d", &a[i]);
        memset(vis, 0, sizeof vis);
        cnt = 0;
        mod = n + 1;
        for(int i=0; i<=m; i++){
            sum = 0;
            for(int j=0; j<=k; j++){
                sum = (sum + a[j] * pw(i, j)) % mod;
            }
            if(!vis[sum]){
                vis[sum] = 1; cnt++;
            }
        }
        printf("%d\n", cnt);
    }


}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define inf 1000000000

int h, k, in[(1<<20) + 10], memo[1<<20][20], n;

int dp(int u, int rem)
{
    if(rem <= 0) return -inf;
    if(2 * u >= n) return in[u];
    int &ret = memo[u][rem];
    if(ret != -1) return ret;
    ret = in[u];
    int temp;
    for(int i=1; i<rem; i++){
        temp = dp(2 * u, i) + dp(2 * u + 1, rem - i);
        if(ret < temp) ret = temp;
    }
    return ret;
}

void read(int n, int p)
{
    scanf("%d", &in[p]);
    if(n){
        read(n - 1, 2 * p);
        read(n - 1, 2 * p + 1);
    }
}

int main()
{
    while(1){
        scanf("%d", &h);
        if(h == -1) return 0;
        scanf("%d", &k);
        n = 1<<(h + 1);
        read(h, 1);
        memset(memo, -1, sizeof memo);
        printf("%d\n", dp(1, k) );
    }
}

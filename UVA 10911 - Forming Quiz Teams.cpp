#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define vi vector<int>
#define vii vector< vector<int> >

int n;
double memo[(1<<16)];
vii in;

double dp(int u)
{
    
//  If all the 2*n bits in u are set ( all contestants are paired ) then
//  this is a possible answer. 
    if(u == (1<<2*n) - 1) return 0.0;
    
//  If this state was reached before, return the answer.
    double &ret = memo[u];
    if(ret != -1.0) return ret;
    
// Try to find all other possible pairings.
    ret = inf;
    int temp;
    for(int i=0; i<2 * n; i++){
        if((1<<i) & u) continue;
        for(int j = i + 1; j<2 * n; j++){
            if((1<<j) & u) continue;
            temp = u | (1<<i) | (1<<j);
            ret = min(ret, dp(temp) + hypot(in[i][0] - in[j][0], in[i][1] - in[j][1]) );
        }
    }
    return ret;
}

int main()
{
    int tc = 1;
    char s[25];
    while(1){
        scanf("%d", &n);
        if(!n) return 0;
        int x, y;
        in.assign(2 * n, vi(2) );
        for(int i=0; i<(1<<(2*n)); i++) memo[i] = -1.0;
        for(int i=0; i<2 * n; i++){
            scanf("%s%d%d", &s, &in[i][0], &in[i][1]);
        }
        printf("Case %d: %.2lf\n", tc++, dp(0) );
    }
}

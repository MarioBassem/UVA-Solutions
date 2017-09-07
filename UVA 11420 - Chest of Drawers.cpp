#include <bits/stdc++.h>

using namespace std;

int n,s;
long long memo[70][2][70];

long long dp(int u,int last,int rem)
{

    if(rem<0) return 0;

    if(u==0){
        if(!rem) return 1;
        return 0;
    }

    long long &ret = memo[u][last][rem];
    if(ret != -1) return ret;

    int x = rem;
    if(last) --x;

    return ret = dp(u-1,0,rem) + dp(u-1,1,x);
}

int main()
{

    memset(memo,-1,sizeof memo);
    while(1){
        scanf("%d%d",&n,&s);
        if( n<0 && s<0) break;
        cout<<dp(n,1,s)<<endl;
    }
}

// Since memo indices could be negative, I mapped negative
// possible indices to possible ones using two unordered maps.

#include <bits/stdc++.h>

using namespace std;

int n, q, input[210], d, m;
long long memo[210][55][15];
unordered_map<int, int> mp, mp2;

long long dp(int u, int temp, int rem)
{
    int sum = mp2[temp];
    if(!rem){
        if(!sum) return  1;
        return 0;
    }
    if(u == n) return 0;
    long long &ret = memo[u][mp[sum]][rem];
    if(ret != -1) return ret;
    return ret = dp(u+1, mp[(sum + input[u]) % d], rem - 1) + dp(u+1, mp[sum], rem);
}

int main()
{

    for(int i=-20; i<=20; i++)
        mp[i] = i + 20, mp2[i + 20] = i;

    int st = 1;
    while(1){
        scanf("%d%d", &n, &q);
        if(!n && !q) break;
        for(int i=0; i<n; i++){
            scanf("%d", &input[i]);
        }
        printf("SET %d:\n", st++);
        for(int i=1; i<=q; i++){
            scanf("%d%d", &d, &m);
            memset(memo, -1, sizeof memo);
            printf("QUERY %d: %lld\n", i, dp(0, mp[0], m) );
        }
    }

}

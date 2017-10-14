#include <bits/stdc++.h>

using namespace std;

int n, in[25], memo[4][1<<20], len;

bool dp(int num, int u, int sum)
{
    if(u == (1<<n) - 1 && num == 4) return 1;

    int &ret = memo[num][u];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<n; i++){
        if( !((1<<i) & u) ){
            if(sum + in[i] < len){
                if(dp(num, u | (1<<i), sum + in[i])) return 1;
            }else if(sum + in[i] == len)
                if(dp(num + 1, u | (1<<i), 0) ) return 1;
        }
    }
    return ret;

}

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        int sum = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &in[i]);
            sum += in[i];
        }
        if(sum % 4){
            printf("no\n");
            continue;
        }
        len = sum / 4;
        memset(memo, -1, sizeof memo);
        if(dp(0, 0, 0)) printf("yes\n");
        else printf("no\n");

    }
}

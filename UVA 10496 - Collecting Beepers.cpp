#include <bits/stdc++.h>

using namespace std;

int memo[15][4100], n, m, input[15][2], beepers;

int dp(int u, int reached)
{
    if(reached == (1<<beepers) - 1 )
        return abs(input[u][0] - input[0][0]) + abs(input[u][1] - input[0][1]);

    int &ret = memo[u][reached];
    if(ret != -1) return ret;

    ret = inf;
    for(int i=1; i<beepers; i++){
        if(!((1<<i) & reached) ){
            int temp = abs(input[u][0] - input[i][0]) + abs(input[u][1] - input[i][1]);
            ret = min(ret, temp + dp(i, reached + (1<<i)) );
        }
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        scanf("%d%d", &input[0][0], &input[0][1]);
        scanf("%d", &beepers);
        beepers++;
        for(int i=1; i<beepers; i++){
            scanf("%d%d", &input[i][0], &input[i][1]);
        }
        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", dp(0, 1));
    }


}

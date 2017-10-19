#include <bits/stdc++.h>

using namespace std;

#define vii vector<vector<int> >
#define vi vector<int>
#define inf 1000000000

int s, n, m;
int cost[100], memo[1<<16][100];
vii in;

int dp(int u, int j)
{

    if(j == n && u < (1<<(2*s)) - 1) return inf;
    if(u == (1<<(2*s)) - 1) return 0;

    int &ret = memo[u][j];
    if(ret != -1) return ret;

    ret = inf;
    int t;
    for(int i = j; i<n; i++){
        t = u;
        for(int k=0; k<in[i].size(); k++){
            if(t & (1<<in[i][k]) ) t |= 1<<(in[i][k] + s);
            else t |= 1<<in[i][k];
        }
        ret = min(ret, dp(t, i + 1) + cost[i] );
    }
    return ret;

}


int main()
{
    while(1){

        scanf("%d%d%d", &s, &m, &n);
        if(!s) return 0;
        in.assign(n, vi(0) );
        memset(memo, -1, sizeof memo);

        int x, u = 0, sum = 0;
        for(int i=0; i<m; i++){
            scanf("%d", &x);
            sum += x;
            while(getchar() != '\n'){
                scanf("%d", &x);
                x--;
                if(u & (1<<x)) u |= 1<<(x + s);
                else u |= 1<<x;
            }
        }

        for(int i=0; i<n; i++){
            scanf("%d", &cost[i]);
            while(getchar() != '\n'){
                scanf("%d", &x);
                x--;
                in[i].push_back(x);
            }
        }

        printf("%d\n", sum + dp(u, 0));
    }
}

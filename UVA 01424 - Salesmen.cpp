#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< vector<int> >
#define mod 1000000007

vii adj;
int in[200], p, memo[200][100];

int dp(int u, int last)
{
    if(u == p) return 0;

    int &ret = memo[u][last];
    if(ret != -1) return ret;

    int temp, x = 1;
    if(in[u] == last) x = 0;
    ret = dp(u + 1, last) + x;
    for(int i=0; i<adj[last].size(); i++){
        temp = dp(u + 1, adj[last][i]);
        if(in[u] != adj[last][i]) temp++;

        if(ret > temp) ret = temp;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        adj.assign(n, vi(0) );

        int x, y;
        for(int i=0; i<m; i++){
            scanf("%d%d", &x, &y);
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        scanf("%d", &p);
        for(int i=0; i<p; i++){
            scanf("%d", &in[i]);
            in[i]--;
        }

        memset(memo, -1, sizeof memo);
        int mn = inf, temp;
        for(int i=0; i<n; i++){
            temp = dp(1, i);
            if(in[0] != i) temp++;

            if(mn > temp) mn = temp;
        }
        printf("%d\n", mn);

    }
}

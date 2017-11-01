#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define inf 1000000000
#define vvi vector< vector<int> >

vvi adjList;
int n;
int memo[10000][10];
bool isRoot[10000];

int dp(int u, int k)
{

    if(adjList[u].size() == 0) return k;

    int &ret = memo[u][k];
    if(ret != -1) return ret;

    ret = k;
    int v, temp;
    for(int i=0; i<adjList[u].size(); i++){
        v = adjList[u][i];
        temp = inf;
        for(int l=1; l<=9; l++){
            if(k == l) continue;
            temp = min(temp, dp(v, l) );
        }
        ret += temp;
    }
    return ret;
}

int main()
{
    while(1){
        scanf("%d", &n);
        if(!n) return 0;
        adjList.assign(n, vi(0) );
        memset(isRoot, 1, sizeof isRoot);

        int x, y;
        for(int i=0; i<n; i++){
            scanf("%d", &x);
            getchar();
            while(getchar() != '\n'){
                scanf("%d", &y);
                isRoot[y] = 0;
                adjList[x].push_back(y);
            }
        }

        int root;
        for(int i=0; i<n; i++)
            if(isRoot[i]){
                root = i;
                break;
            }

        memset(memo, -1, sizeof memo);
        int ans = inf;
        for(int i=1; i<=9; i++){
            ans = min(ans, dp(root, i) );
        }
        printf("%d\n", ans );

    }
}

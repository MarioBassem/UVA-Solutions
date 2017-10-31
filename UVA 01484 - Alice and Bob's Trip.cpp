#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int, int> >
#define vvi vector< vector<int> >
#define vvl vector< vector<long long> >
#define vvii vector< vector< pair<int, int > > >

int n, l, r, memo[500000], ba;
ll dist[500000];
vvii adjList;

void dfs(int u)
{
    int v, w;
    for(int i=0; i<adjList[u].size(); i++){
        v = adjList[u][i].first; w = adjList[u][i].second;
        dist[v] = dist[u] + w;
        dfs(v);
    }
}

int dp(int u)
{

    if(adjList[u].size() == 0) return 0;
    int &ret = memo[u];
    if(ret != -1) return ret;
    int path, v, w, t1 = 0, t2 = inf;
    for(int i=0; i<adjList[u].size(); i++){
        v = adjList[u][i].first; w = adjList[u][i].second;
        ba = 1 - ba;
        path = dist[u] + w + dp(v);
        ba = 1 - ba;
        if(path >= l && path <= r){
            if(!ba) t1 = max(ll (t1), path - dist[u]);
            else t2 = min(ll (t2), path - dist[u]);
        }

    }
    if(!ba) return t1;
    return t2;

}

int main()
{
    while(scanf("%d%d%d", &n, &l, &r) == 3){
        adjList.assign(n, vii(0, ii(0, 0) ) );
        int a, b, c;
        for(int i=0; i<n-1; i++){
            scanf("%d%d%d", &a, &b, &c);
            adjList[a].push_back(ii(b, c) );
        }
        dist[0] = 0;
        dfs(0);
        memset(memo, -1, sizeof memo);
        ba = 0;
        int ans = dp(0);

	if(ans >= l && ans <= r) printf("%d\n", ans);
        else printf("Oh, my god!\n");
    }
}

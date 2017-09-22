
// Used Edmond Karp's max flow algorithm to determine the maximum number
// of gophers who are not vulnerable.

#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define vi vector<int>
#define vii vector< vector<int> >

int n, m, s, v, res[210][210], maxFlow, flow;
vi p;

void augment(int v, int minEdge)
{
    if(v == 0){
        flow = minEdge; return;
    }else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]) );
        res[p[v]][v] -= flow;
        res[v][p[v]] += flow;
    }
}

int main()
{
    unordered_map<int, pair<double, double> > coordinates;
    vii adj;
    while(cin>>n>>m>>s>>v){
        adj.assign(n+m+2, vi(0) );
        double x, y;
        for(int i=1; i<=n+m; i++){
            scanf("%lf%lf", &x, &y);
            coordinates[i].first = x;
            coordinates[i].second = y;
        }

        memset(res, 0, sizeof res);

        for(int i=1; i<=n; i++){
            for(int j=n+1; j<=n+m; j++){
                double diff1 = coordinates[i].first - coordinates[j].first;
                double diff2 = coordinates[i].second - coordinates[j].second;
                double dist = sqrt(diff1 * diff1 + diff2 * diff2);
                if(dist / v <= s){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    res[i][j] = 1;
                }
            }
        }

//      Connecting the dummy source to all gophers.

        for(int i=1; i<=n; i++){
            adj[0].push_back(i);
            res[0][i] = 1;
        }

//	Connecting all the holes to the dummy sink.

        for(int i=n+1; i<=n+m; i++){
            adj[i].push_back(n+m+1);
            res[i][n+m+1] = 1;
        }

//	Edmond Karp's algorithm.

        maxFlow = 0;
        while(1){
            flow = 0;
            bool vis[210] = {false};
            p.assign(210, -1);
            queue<int> q;
            q.push(0);
            vis[0] = 1;
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u == n+m+1) break;
                for(int i=0; i<adj[u].size(); i++){
                    int v = adj[u][i];
                    if(res[u][v] && !vis[v])
                        vis[v] = 1, q.push(v), p[v] = u;
                }
            }
            augment(n+m+1, inf);
            if(!flow) break;
            maxFlow +=flow;
        }
        printf("%d\n", n-maxFlow);
    }
}

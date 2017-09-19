#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define vi vector<int>

int res[50][50], maxFlow, flow;
vector<vi> adj(38);
vi p;

void augment(int v, int minEdge)
{
    if(v==0){
        flow = minEdge; return;
    }else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= flow;
        res[v][p[v]] += flow;
    }
}

void EdmondKarp()
{
    maxFlow = 0;
    while(1){
        flow = 0;
        bool dist[40];
        memset(dist, 0, sizeof dist);
        queue<int> q; q.push(0);
        dist[0] = 1;
        p.assign(38, -1);
        while(!q.empty()){
            int v, u = q.front(); q.pop();
            if(u == 37) break;
            for(int i=0; i<adj[u].size(); i++){
                v = adj[u][i];
                if( res[u][v] && !dist[v] ){
                    q.push(v), dist[v] = 1, p[v] = u;
                }
            }
        }
        augment(37, inf);
        if(!flow) break;
        maxFlow += flow;
    }
}


int main()
{
    string s,ans;
    int numberOfApps = 0;
    bool ch=0;
    while(1){
        getline(cin, s);
        if(!s.size()) {
            if(!ch) break;
            ch = 0;
            EdmondKarp();
            if(maxFlow != numberOfApps) printf("!\n");
            else{
                ans = "__________";
                for(int i=27; i<37; i++){
                    for(int j=1; j<27; j++)
                        if(res[i][j]){
                            ans[i-27] = char('A' + j - 1);
                            break;
                        }
                }
                cout<<ans<<endl;
            }
            for(int i=0; i<38; i++) adj[i].clear();
            memset(res, 0, sizeof res);
            numberOfApps = 0;
        }else{
            ch = 1;
            numberOfApps += s[1]-'0';
            int x = s[0] - 'A' + 1, y;
            adj[0].push_back(x);
            res[0][x] = s[1]-'0';
            for(int i=3; i<s.length()-1; i++){
                y = s[i] - '0' + 27;
                adj[x].push_back(y);
                adj[y].push_back(x);
                adj[y].push_back(37);
                res[x][y] = inf;
                res[y][37] = 1;
            }
        }
    }
}

#include <bits/stdc++.h>

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >

using namespace std;

vector<pair<int, ii> > edgeList;
int n, m;
vi p;
vector<bool> valid, used;

int findSet(int u)
{
    if(p[u] == -1) return u;
    return p[u] = findSet(p[u]);
}

int MinimumSpanningTree(bool flag)
{
    p.assign(n+1, -1);
    int sets = n;
    int a, b, c, total = 0;
    for(int i=0; i<edgeList.size(); i++){
        if(valid[i]){
            c = edgeList[i].first;
            a = edgeList[i].second.first;
            b = edgeList[i].second.second;
            if(findSet(a) != findSet(b)){
                if(flag) used[i] = 1;
                p[findSet(a)] = findSet(b);
                sets--;
                total += c;
            }
        }
    }
    if(sets == 1) return total;
    else return inf;
}

int secondMinimum()
{
    int mn = inf, temp;
    for(int i=0; i<m; i++){
        if(used[i] == 1){
            valid[i] = 0;
            temp = MinimumSpanningTree(0);
            if(temp < mn)
                mn = temp;
            valid[i] = 1;
        }
    }
    return mn;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        edgeList.clear();
        int a, b, c;
        for(int i=0; i<m; i++){
            scanf("%d%d%d", &a, &b, &c);
            edgeList.push_back(make_pair(c, ii(a, b) ) );
        }
        sort(edgeList.begin(), edgeList.end() );
        used.assign(m, 0);
        valid.assign(m, 1);
        int x = MinimumSpanningTree(1);
        int y = secondMinimum();
        printf("%d %d\n", x, y);

    }

}

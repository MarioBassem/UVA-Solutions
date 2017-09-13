#include <bits/stdc++.h>

#define inf 1000000000000000000
#define ii pair<int, int>

using namespace std;

int n, m, parent[1010];
vector< pair<int, ii> > edgeList;
vector<int> heavy;

int findset(int u)
{
    if(parent[u] == u) return u;
    return parent[u] = findset(parent[u]);
}

void Kruskal()
{
    sort(edgeList.begin(), edgeList.end());
    int a, b;
    for(int i=0; i<m; i++){
        a = findset(edgeList[i].second.first);
        b = findset(edgeList[i].second.second);
        if(a != b){
            parent[a] = b;
        }else heavy.push_back(edgeList[i].first);
    }
}

int main()
{
    while(1)
    {
        edgeList.clear();
        scanf("%d%d", &n, &m);
        if( !n && !m ) break;
        int a, b, c;
        for(int i=0; i<m; i++){
            scanf("%d%d%d", &a, &b, &c);
            edgeList.push_back( make_pair(c, ii(a, b) ) );
        }
        heavy.clear();
        for(int i=0; i<n; i++) parent[i] = i;
        Kruskal();
        if(heavy.size()){
            sort(heavy.begin(), heavy.end());
            printf("%d", heavy[0]);
            for(int j=1; j<heavy.size(); j++) printf(" %d", heavy[j]);
            printf("\n");
        }else printf("forest\n");
    }

}

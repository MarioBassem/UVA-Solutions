#include <bits/stdc++.h>

#define inf 1000000000000000000
#define ii pair<int, int>

using namespace std;

int n, r, parent[1010];

int findset(int u)
{
    if(parent[u] == u) return u;
    return parent[u] = findset(parent[u]);
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int k=1; k<=tc; k++){
        scanf("%d%d", &n, &r);
        vector< ii > city(n);
        vector< pair<double, ii > > edges;
        for(int i=0; i<n; i++) parent[i] = i;

        for(int i=0; i<n; i++)
            scanf("%d %d", &city[i].first, &city[i].second);

        double temp;
        int a, b;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                a = abs(city[i].first - city[j].first);
                b = abs(city[i].second - city[j].second);
                temp = sqrt(a * a + b * b);
                edges.push_back(make_pair(temp, ii(i, j) ) );
            }
        }
        double roads = 0, railroads = 0;
	int states = n;
        sort(edges.begin(), edges.end());
        ii p;
        for(int i=0; i<edges.size(); i++){
            p = edges[i].second;
            a = findset(p.first);
            b = findset(p.second);
            if(a != b){
                parent[a] = b;
                if(edges[i].first > r) railroads += edges[i].first ;
                else {
                    roads += edges[i].first;
                    states--;
                }
            }
        }
        printf("Case #%d: %d %d %d\n", k, states, (int)floor(roads + .5), (int)floor(railroads + .5) );
    }

}

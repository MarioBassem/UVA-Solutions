#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

int input[1000000], dist[1000000], n, m;

void Dijkstra()
{
    for(int i = 1; i < n * m; i++ ) dist[i] = inf;
    dist[0] = input[0];
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push( make_pair( dist[0], 0 ) );
    pair<int, int> p;
    int d, u;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        d = p.first;
        u = p.second;
        if(d > dist[u]) continue;
        if(u - m > 0 && dist[u-m] > dist[u] + input[u-m]){
            dist[u-m] = dist[u] + input[u-m];
            pq.push( make_pair( dist[u-m], u-m ) );
        }
        if(u + m < n*m && dist[u+m] > dist[u] + input[u+m]){
            dist[u+m] = dist[u] + input[u+m];
            pq.push( make_pair( dist[u+m], u+m ) );
        }
        if(u%m != 0 && dist[u-1] > dist[u] + input[u-1]){
            dist[u-1] = dist[u] + input[u-1];
            pq.push( make_pair( dist[u-1], u-1 ) );
        }
        if(u%m != m-1 && dist[u+1] > dist[u] + input[u+1]){
            dist[u+1] = dist[u] + input[u+1];
            pq.push( make_pair( dist[u+1], u+1 ) );
        }
    }
}


int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n * m; i++ ){
            scanf("%d", &input[i]);
        }
        Dijkstra();
        printf("%d\n", dist[n * m - 1]);
    }
}

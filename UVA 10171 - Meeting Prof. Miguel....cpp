#include <bits/stdc++.h>

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >

using namespace std;

vector<vector< ii> > oldAdj(26), youngAdj(26);
int youngDist[30], oldDist[30];

void YoungDijkstra(int s)
{
    for(int i=0; i<30; i++){
        youngDist[i] = inf;
    }
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    youngDist[s] = 0;
    pq.push( ii(0, s) );
    while(!pq.empty()){
        ii p = pq.top(); pq.pop();
        for(int i=0; i<youngAdj[p.second].size(); i++){
            ii v = youngAdj[p.second][i];
            if(youngDist[v.first] > youngDist[p.second] + v.second){
                youngDist[v.first] = youngDist[p.second] + v.second;
                pq.push(ii(youngDist[v.first], v.first) );
            }
        }
    }
}

void OldDijkstra(int s)
{
    for(int i=0; i<30; i++){
        oldDist[i] = inf;
    }
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    oldDist[s] = 0;
    pq.push(ii(0, s) );
    while(!pq.empty()){
        ii p = pq.top(); pq.pop();
        for(int i=0; i<oldAdj[p.second].size(); i++){
            ii v = oldAdj[p.second][i];
            if(oldDist[v.first] > oldDist[p.second] + v.second){
                oldDist[v.first] = oldDist[p.second] + v.second;
                pq.push(ii(oldDist[v.first], v.first) );
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        for(int i=0; i<26; i++)
            youngAdj[i].clear(), oldAdj[i].clear();
        char a, b, c, d;
        int weight;
        for(int i=0; i<n; i++){
            cin>>a>>b>>c>>d>>weight;
            if(a == 'Y'){
                youngAdj[c - 'A'].push_back(ii(d-'A', weight) );
                if(b == 'B'){
                    youngAdj[d-'A'].push_back(ii(c-'A', weight) );
                }
            }else{
                oldAdj[c - 'A'].push_back(ii(d-'A', weight) );
                if(b == 'B'){
                    oldAdj[d-'A'].push_back(ii(c-'A', weight) );
                }
            }
        }
        cin>>a>>b;
        OldDijkstra(int(b-'A'));
        YoungDijkstra(int(a-'A'));
        vector<int> ans;
        int mn = inf;
        for(int i=0; i<26; i++){
            if(youngDist[i] + oldDist[i] < mn){
                ans.clear();
                ans.push_back(i);
                mn = youngDist[i] + oldDist[i];
            }else if(youngDist[i] + oldDist[i] == mn)
                ans.push_back(i);
        }
        if(mn < inf){
            printf("%d", mn);
            for(int i=0; i<ans.size(); i++){
                printf(" %c", char(ans[i] + 'A'));
            }
        }else printf("You will never meet.");
        printf("\n");

    }
}

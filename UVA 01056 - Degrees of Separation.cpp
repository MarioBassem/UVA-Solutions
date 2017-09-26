// Used Floyd Warshall's algorithm to calculate all pairs shortest paths


#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

unordered_map<string, int> mp;
int dist[55][55];

int main()
{
    int p, r,cnt, tc = 1;
    string s1, s2;
    while(1){
        scanf("%d%d", &p, &r);
        mp.clear();
        cnt = 1;
        if(!p && !r) break;

        for(int i=1; i<=p; i++)
            for(int j=1; j<=p; j++)
                if(i != j) dist[i][j] = inf;
                else dist[i][j] = 0;

        for(int i=0; i<r; i++){
            cin>>s1>>s2;
            if(!mp[s1]) mp[s1] = cnt++;
            if(!mp[s2]) mp[s2] = cnt++;
            dist[mp[s1]][mp[s2]] = 1;
            dist[mp[s2]][mp[s1]] = 1;
        }

//        Floyd Warshall's Algorithm

        int mx = -1;
        for(int k=1; k<=p; k++){
            for(int i=1; i<=p; i++){
                for(int j=1; j<=p; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                    if(k==p && dist[i][j] > mx)
                        mx = dist[i][j];
                }
            }
        }
        printf("Network %d: ", tc++);
        if(mx == inf) printf("DISCONNECTED\n\n");
        else printf("%d\n\n", mx);
    }

}

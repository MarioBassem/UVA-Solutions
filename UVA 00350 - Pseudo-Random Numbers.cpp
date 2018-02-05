#include <bits/stdc++.h>
#define EPS 1e-9
#define PI 3.14159265359
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >

typedef long long ll;

using namespace std;

int main()
{
    int Z, I, M, L, cnt, tc = 1;
    unordered_map<int, int> mp;
    while(1){
        scanf("%d%d%d%d", &Z, &I, &M, &L);
        if(!Z && !I && !M && !L) return 0;
        mp[L] = 1;
        cnt = 2;
        int temp;
        while(1){
            temp = (ll(Z) * L + I) % M;
            if(mp[temp]){
                printf("Case %d: %d\n", tc++, cnt - mp[temp]);
                break;
            }else L =  temp, mp[temp] = cnt++;
        }
        mp.clear();
    }
}

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
    int x;
    unordered_map<int, bool> mp;
    while(scanf("%d", &x) == 1){
        int sz1 = 0, sz2 = 0, cnt = 0;
        mp[x] = 1;
        sz1++;
        while(getchar() != '\n'){
            scanf("%d", &x);
            mp[x] = 1;
            sz1++;
        }
        scanf("%d", &x);
        sz2++;
        if(mp[x]) cnt++;
        while(getchar() != '\n'){
            scanf("%d", &x);
            sz2++;
            if(mp[x]) cnt++;
        }
        if(sz1 == sz2 && cnt == sz2) printf("A equals B\n");
        else if(sz1 > sz2 && cnt == sz2) printf("B is a proper subset of A\n");
        else if(sz1 < sz2 && cnt == sz1) printf("A is a proper subset of B\n");
        else if(cnt) printf("I'm confused!\n");
        else printf("A and B are disjoint\n");

        mp.clear();
    }
}

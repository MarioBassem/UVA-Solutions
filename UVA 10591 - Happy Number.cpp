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
    int n, tc;
    unordered_map<int, bool> mp;
    scanf("%d", &tc);
    for(int testCase = 1; testCase <= tc; testCase++){
        scanf("%d", &n);
        mp[n] = 1;
        int s1 = n, s2 = 0;
        while(1){
            while(s1){
                s2 += (s1 % 10) * (s1 % 10);
                s1 /= 10;
            }
            if(mp[s2]){
                if(s2 == 1) printf("Case #%d: %d is a Happy number.\n", testCase, n);
                else printf("Case #%d: %d is an Unhappy number.\n", testCase, n);
                break;
            }
            mp[s2] = 1;
            s1 = s2; s2 = 0;
        }
        mp.clear();

    }
}

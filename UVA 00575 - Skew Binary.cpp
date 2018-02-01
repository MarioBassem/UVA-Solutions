#include <bits/stdc++.h>
#define EPS 1e-9
#define PI 3.14159265359
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >

typedef long long ll;

using namespace std;

ll pw(ll u, ll e)
{
    if(e == 1) return u;
    if(!e) return 1;
    ll temp = pw(u, e / 2);
    temp = (temp * temp);
    if(e % 2) temp = (temp * u);
    return temp;

}

int main()
{
    string s;
    int sum, l;
    while(1){
        cin>>s;
        l = s.length() - 1;
        if(l == 0 && s[0] == '0') return 0;
        sum = 0;
        for(int i=0; i<=l; i++){
            sum += (s[l - i] - '0') * (pw(2, i + 1) - 1);
        }
        printf("%d\n", sum);
    }
}

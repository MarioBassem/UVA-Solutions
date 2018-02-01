#include <bits/stdc++.h>
#define EPS 1e-9
#define PI 3.14159265359
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >

typedef long long ll;

using namespace std;

ll mod = 1000000009;

ll pw(ll u, ll e)
{
    if(e == 1) return u;
    if(!e) return 1;
    ll temp = pw(u, e / 2);
    temp = (temp * temp);
    if(e % 2) temp = (temp * u);
//    cout<<temp<<" "<<e<<endl;
    return temp;

}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ll hn, ln;
    while(1){
        cin>>hn>>ln;
        if(!hn && !ln) return 0;
        if(hn == 1 && ln == 1){
            printf("0 1\n"); continue;
        }
        int p;
        for(int i=1; i<32; i++){
            double temp = pow(hn, 1.0 / i) - pow(ln, 1.0 / i);
            if(temp <= 1 + EPS && temp >= 1 - EPS){
                p = i; break;
            }
        }
        int N = pow(ln, 1.0 / p) + 0.001;
        ll sumN = 0;
        for(int i=0; i<=p; i++){
            sumN += pw(N, i);
        }
        sumN -= ln;
        ll sumH = 0;
        for(int i=0; i<=p; i++){
            sumH += pw(N, i) * hn;
            hn /= (N + 1);
        }
        cout<<sumN<<" "<<sumH<<endl;
    }


}

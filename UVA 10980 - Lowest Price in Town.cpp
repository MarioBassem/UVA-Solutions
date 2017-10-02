#include <bits/stdc++.h>

using namespace std;

vector<pair<int, double> > in(25);
int m, k;
double memo[110];

double dp(int cnt)
{
    if(cnt >= k)
        return 0.000;

    double &ret = memo[cnt];
    if(ret != -1) return ret;

    ret = inf;
    for(int i=0; i<=m; i++){
        ret = min(ret, in[i].second + dp(cnt + in[i].first) );
    }
    return ret;
}


int main()
{
    double temp;
    int tc = 1;
    while(cin>>temp>>m){
        in[0].first = 1; in[0].second = temp;

        for(int i=1; i<=m; i++){
            scanf("%d %lf", &in[i].first, &in[i].second);
        }

        getchar();
        printf("Case %d:\n", tc++);

        while(1){
            scanf("%d", &k);
            for(int i=0; i<110; i++) memo[i] = -1;
            printf("Buy %d for $%.2lf\n", k, dp(0) );
            if(getchar() == '\n') break;
        }
    }

}

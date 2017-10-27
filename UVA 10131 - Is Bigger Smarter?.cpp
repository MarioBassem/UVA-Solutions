#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define vi vector<int>
#define vii vector< vector<int> >

vii in;
int memo[1000], n;

int dp(int u)
{
    int &ret = memo[u];
    if(ret != -1) return ret;
    ret = 1;
    for(int i=u+1; i<n; i++){
        if(in[i][0] > in[u][0] && in[i][1] < in[u][1]) ret = max(ret, 1 + dp(i) );
    }
    return ret;
}

void path(int u, int x)
{
    printf("%d\n", in[u][2]);
    for(int i=u+1; i<n; i++){
        if(memo[i] == x) {
            path(i, x-1); return;
        }
    }
}

int main()
{
    int it = 1;
    vi temp(3);
    while(scanf("%d%d", &temp[0], &temp[1]) == 2){
        temp[2] = it++;
        in.push_back(temp);
    }
    n = in.size();
    sort(in.begin(), in.end());
    memset(memo, -1, sizeof memo);
    int t = 0;
    for(int i=0; i<n; i++){
        t = max(t, dp(i) );
    }
    printf("%d\n", t);
    for(int i=0; i<n; i++){
        if(memo[i] == t){
            path(i, t-1); return 0;
        }
    }






}

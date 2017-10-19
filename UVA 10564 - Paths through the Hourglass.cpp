#include <bits/stdc++.h>

using namespace std;

#define vii vector<vector<int> >
#define inf 1000000000

string path, ans;
long long memo[40][20][500];
int n, s;
vii in;

long long dp(int i, int j, int sum)
{
    if(i == 2 * n - 2){
        if(j < 0 || j == in[i].size()) return 0;
        if(sum + in[i][j] == s) {
            if(ans.length() == 0) ans = path;
            return 1;
        }
        return 0;
    }
    if(j < 0 || j == in[i].size()) return 0;

    long long &ret = memo[i][j][sum];
    if(ret != -1) return ret;

    ret = 0;
    if(i < n - 1){
        path.push_back('L');
        ret += dp(i + 1, j -1 , sum + in[i][j]);
        path.pop_back();
        path.push_back('R');
        ret += dp(i + 1, j, sum + in[i][j]);
        path.pop_back();
    }else{
        path.push_back('L');
        ret += dp(i + 1, j, sum + in[i][j]);
        path.pop_back();
        path.push_back('R');
        ret += dp(i + 1, j + 1, sum + in[i][j]);
        path.pop_back();
    }
    return ret;
}


int main()
{

    while(1){
        scanf("%d%d", &n, &s);
        if(!n && !s) return 0;
        ans.clear();
        in.assign(2 * n - 1, vi(0) );
        int p = n, x = -1;
        for(int i=0; i<2 * n - 1; i++){
            in[i].assign(p, 0);
            for(int j = 0; j<p; j++){
                scanf("%d", &in[i][j]);
            }
            p += x;
            if(!p){
                x = 1;
                p = 2;
            }
        }

        memset(memo, -1, sizeof memo);
        long long t = 0;
        int start = -1;
        for(int i=0; i<n; i++){
            t += dp(0, i, 0);
            if(start == -1 && ans.size()) start = i;

        }
        
        if(ans.size()){
            printf("%lld\n", t);
            cout<<start<<" "<<ans<<endl;
        }else printf("0\n\n");

    }
}

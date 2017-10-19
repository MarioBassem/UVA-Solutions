#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000

int val[1001][27];
int k, blocks, sum, memo[1001][27];
string s;

int dp(int u, int last)
{
    if(u == blocks) return sum;

    int &ret = memo[u][last];
    if(ret != -1) return ret;

    ret = inf;
    int t = u * k, temp;
    for(int i=0; i<k; i++){
        if(s[t + i] - 'a' == last && val[u][last] != k) continue;

        temp = dp(u + 1, s[t + i] - 'a');
        if(val[u + 1][s[t + i] - 'a'] ) temp--;

        if(temp < ret) ret = temp;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &k);
        cin>>s;
        blocks = s.length() / k;
        memset(val, 0, sizeof val);
        memset(memo, -1, sizeof memo);
        sum = 0;
        for(int i=0; i<blocks; i++){
            for(int j=0; j<k; j++){
                if(!val[i][s[i * k + j] - 'a']) sum++;
                val[i][s[i * k + j] - 'a']++;
            }
        }
        printf("%d\n", dp(0, 26));
    }
}

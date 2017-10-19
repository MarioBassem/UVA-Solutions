#include <bits/stdc++.h>

using namespace std;

#define vii vector<vector<int> >
#define vi vector<int>
#define ii pair<int, int>
#define inf 1000000000

string s;
int memo[200][200];

bool check(int a, int b, int k)
{
    for(int i = 0; i<k; i++){
        if(s[i + a] != s[i + b]) return false;
    }
    return true;
}

pair<int, int> valid(int i, int j)
{
    int half = (j - i + 1) / 2, temp;
    bool ch;
    for(int k = 1; k <= half; k++){
        if( (j - i + 1) % k ) continue;

        ch = 1;
        temp = (j - i + 1) / k;

        for(int l = 1; l < temp; l++){
            if(!check(i, i + l * k, k)){
                ch = 0;
                break;
            }
        }
        if(ch) return ii(temp, k);
        
    }
    return ii(inf, j - i + 1);
}


int dp(int i, int j)
{
    if(i == j) return 1;

    int &ret = memo[i][j];
    if(ret != -1) return ret;

    ret = inf;
    ii x = valid(i, j);
    int temp = 0;
    while(x.first){
        temp++;
        x.first /= 10;
    }
    ret = 2 + temp + dp(i, i + x.second - 1);
    for(int k = i; k < j; k++){
        ret = min(ret, dp(i, k) + dp(k + 1, j) );
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        cin>>s;
        memset(memo, -1, sizeof memo);
        printf("%d\n", dp(0, s.length() - 1) );

    }


}

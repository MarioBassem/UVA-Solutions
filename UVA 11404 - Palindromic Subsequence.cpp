#include <bits/stdc++.h>

using namespace std;

string s temp;
pair<int, string> memo[1010][1010];

pair<int, string> best(pair<int, string> a, pair<int, string> b)
{
    if(a.first > b.first) return a;
    if(b.first > a.first) return b;
    if(a.second < b.second) return a;
    return b;
}

pair<int, string> dp(int i, int j)
{
    if(i == j) return make_pair(1, temp = s[i]);
    if(i > j) return make_pair(0, "");
    pair<int, string> &ret = memo[i][j];
    if(ret.first != -1) return ret;
    if(s[i] == s[j]){
        ret.first = 2 + dp(i+1, j-1).first;
        ret.second = s[i] + dp(i+1, j-1).second + s[j];
        return ret;
    }

    return ret = best(dp(i, j-1), dp(i+1, j));

}

int main()
{
    while(cin>>s){
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<s.length(); j++)
                memo[i][j].first = -1;
        }
        cout<<dp(0, s.length()-1).second<<endl;
    }
}

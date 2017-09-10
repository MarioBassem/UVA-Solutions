#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long n = 1, d = 1, rn = 1, rd = 0, ln = 0, ld = 1;
};

node getChild(node a, char c)
{
    node ret = a;
    if(c=='R'){
        ret.n = a.n + a.rn;
        ret.d = a.d + a.rd;
        ret.ln = a.n;
        ret.ld = a.d;
    }else{
        ret.n = a.n + a.ln;
        ret.d = a.d + a.ld;
        ret.rn = a.n;
        ret.rd = a.d;
    }
    return ret;
}



int main()
{
    int n;
    scanf("%d",&n);
    string s;
    for(int i=0;i<n;i++){
        node ans;
        cin>>s;
        for(int j=0;j<s.length();j++){
            ans = getChild(ans,s[j]);
        }
        cout<<ans.n<<"/"<<ans.d<<endl;
    }
}

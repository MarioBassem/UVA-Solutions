#include <bits/stdc++.h>

using namespace std;

string s, temp;
int memo[1010][1010], mov[1010][1010];

int dp(int i, int j)
{
    if(i==j || i > j) return 0;
    int &ret = memo[i][j];
    if(ret != -1) return ret;
    if(s[i] == s[j]) {
        mov[i][j] = 0;
        return ret = dp(i+1, j-1);
    }
    if(dp(i+1, j) < dp(i, j-1)){
        mov[i][j] = 1;
    }else mov[i][j] = 2;
    return ret = 1 + min(dp(i+1, j), dp(i, j-1));

}

void path(int i, int j)
{
    if(i == j) {
        cout<<s[i];
        return;
    }
    if(i > j) return;
    if(!mov[i][j]){
        cout<<s[i];
        path(i+1, j-1);
        cout<<s[j];
    }else if(mov[i][j] == 1){
        cout<<s[i];
        path(i+1, j);
        cout<<s[i];
    }else{
        cout<<s[j];
        path(i, j-1);
        cout<<s[j];
    }
}

int main()
{
    while(cin>>s){
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<s.length(); j++)
                memo[i][j] = -1;
        }

        printf("%d ", dp(0, s.length()-1));
        path(0, s.length()-1);
        printf("\n");
    }
}

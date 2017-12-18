#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        string s;
        cin>>s;
        bool f = 0;
        int ans = s.length();
        for(int l = 1; l<=s.length(); l++){
            if(s.length() % l) continue; // Try every possible length for the period
            f = 1;
            for(int i = 0; i<l; i++){
                for(int j=i + l; j<s.length(); j += l){
                    if(s[i] != s[j] ){
                        f = 0; break;
                    }
                }
                if(!f) break;
            }
            if(f){
                ans = l; break;
            }
        }
        printf("%d\n", ans);
        if(n) printf("\n");
    }
}

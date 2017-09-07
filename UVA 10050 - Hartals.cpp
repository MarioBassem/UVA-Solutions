#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        bool vis[n+1];
        memset(vis,1,sizeof vis);
        for(int i=6;i<=n;i+=7){
            vis[i] = vis[i+1] = 0;
        }
        int p,h,ans=0;
        scanf("%d",&p);
        unordered_map<int,bool> mp;
        for(int i=0;i<p;i++){
            scanf("%d",&h);
            if(mp[h]) continue;
            mp[h]=1;
            for(int j=h;j<=n;j+=h){
                if(vis[j]){
                    ans++; vis[j]=0;
                }
            }
        }
        printf("%d\n",ans);
    }
}

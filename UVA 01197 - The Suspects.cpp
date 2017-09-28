#include <bits/stdc++.h>

using namespace std;

int parent[30010],setsize[30010];

int findset(int u)
{
    if(parent[u]==u) return u;
    return parent[u]=findset(parent[u]);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,m;
    while(1){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++){
            parent[i]=i; setsize[i]=1;
        }
        if(!n && !m) break;
        int k,x,y,a,b;
        for(int i=0;i<m;i++){
            scanf("%d",&k);
            if(!k) continue;
            scanf("%d",&x);
            a=findset(x);
            for(int j=1;j<k;j++){
                scanf("%d",&y);
                b=findset(y);
                if(a!=b){
                    setsize[a]+=setsize[b];
                    parent[b]=a;
                }
            }
        }

        printf("%d\n",setsize[findset(0)]);

    }
}

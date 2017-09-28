#include <bits/stdc++.h>

using namespace std;

struct node
{
    int h=0,l=0,s=0;
};

node tree[400010],lazy[400010];

void updateRange(int p,int b,int e,int i,int j,int val)
{
    int x,y,mid=(b+e)/2;
    if(lazy[p].s){
        tree[p].s += lazy[p].s*(e-b+1);
        tree[p].h = lazy[p].h;
        tree[p].l = tree[p].h;
        if(e!=b){
            lazy[2*p].s += lazy[p].s; lazy[2*p].h = lazy[p].h;
            lazy[2*p+1].s += lazy[p].s; lazy[2*p+1].h = lazy[p].h;
        }
        lazy[p].s = 0; lazy[p].h = 0;
    }
    if(i>e || j<b || tree[p].l>val) return;
    if(b>=i && e<=j && val>=tree[p].h){
        tree[p].s += e-b+1;
        tree[p].h = val;
        tree[p].l = val;
        if(e!=b){
            lazy[2*p].s++;
            lazy[2*p].h = val;
            lazy[2*p+1].s++;
            lazy[2*p+1].h = val;
        }
        return;
    }
    if(e==b) return;
    updateRange(2*p,b,mid,i,j,val);
    updateRange(2*p+1,mid+1,e,i,j,val);
    tree[p].s = tree[2*p].s + tree[2*p+1].s;
    tree[p].h = max(tree[2*p].h , tree[2*p+1].h);
    tree[p].l = min(tree[2*p].l , tree[2*p+1].l);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int c,n,l,r,h;
    cin>>c;
    while(c--){
        scanf("%d",&n);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&l,&r,&h);
            r--;
            updateRange(1,1,100000,l,r,h);
        }
        printf("%d\n",tree[1].s);
    }
}

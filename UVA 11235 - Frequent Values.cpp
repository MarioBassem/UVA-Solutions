#include <bits/stdc++.h>

using namespace std;

int a1[100010];

struct node
{
    int lv, rv, ln=1 ,rn=1 ,fr=1000000;
};

node tree[400010];

node merge(node a,node b)
{
    if(a.fr==1000000) return b;
    else if(b.fr==1000000) return a;

    node ret;
    if(a.lv == b.rv){
        ret.fr = a.fr + b.fr;
        ret.ln = ret.rn = ret.fr;
    }else if(a.rv == b.rv){
        ret.fr = max(b.fr + a.rn , a.fr);
        ret.ln = a.ln;
        ret.rn = ret.fr;
    }else if(a.lv == b.lv){
        ret.fr = max(a.fr + b.ln , b.fr);
        ret.ln = ret.fr;
        ret.rn = b.rn;
    }else if(a.rv == b.lv){
        ret.fr = max(a.rn + b.ln , max(a.fr , b.fr));
        ret.ln = a.ln;
        ret.rn = b.rn;
    }else{
        ret.fr = max(a.fr , b.fr);
        ret.ln = a.ln;
        ret.rn = b.rn;
    }
    ret.lv = a.lv;
    ret.rv = b.rv;
    return ret;
}

void build(int p,int b,int e)
{
    if(b==e){
        tree[p].lv = tree[p].rv = a1[b];
        tree[p].ln = tree[p].rn = tree[p].fr = 1;
        return;
    }

    int mid = (b+e)/2;
    build(2*p, b, mid);
    build(2*p+1, mid+1, e);
    tree[p] = merge(tree[2*p] , tree[2*p+1]);
}

node query(int p,int b,int e,int i,int j)
{
    node ret;
    if(i>e || j<b) return ret;
    if(b>=i && e<=j) return tree[p];
    node q1,q2;
    int mid;
    mid = (b+e)/2;
    q1 = query(2*p, b, mid, i, j);
    q2 = query(2*p+1, mid+1, e, i, j);
    return ret = merge(q1 , q2);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,q;
    while(1){
        scanf("%d",&n);
        if(!n) break;
        scanf("%d",&q);
        int x,y;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a1[i]);
        }
        build(1,1,n);
        for(int i=0;i<q;i++){
            scanf("%d%d",&x,&y);
            printf("%d\n",query(1,1,n,x,y).fr);
        }

    }
}

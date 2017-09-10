#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

struct node
{
    int minimum = inf, maximum = -1;
};

node tree[510][4*510];
int input[510];

node merge(node a, node b)
{
    node ret;
    ret.minimum = min(a.minimum, b.minimum);
    ret.maximum = max(a.maximum, b.maximum);
    return ret;
}

void build(int p, int b, int e, int in)
{
    if(b == e){
        tree[in][p].maximum = tree[in][p].minimum = input[b];
        return;
    }
    int mid = (b+e) / 2;
    build(2*p, b, mid, in);
    build(2*p+1, mid+1, e, in);
    tree[in][p] = merge(tree[in][2*p], tree[in][2*p+1]);
}

node query(int p, int b, int e, int i, int j, int in)
{
    node ret;
    if(i > e || j < b) return ret;
    if(b >= i && e <= j) return tree[in][p];
    int mid = (b+e)/2;
    node q1 = query(2*p, b, mid, i, j, in);
    node q2 = query(2*p+1, mid+1, e, i, j, in);
    return merge(q1, q2);
}

void update(int p, int b, int e, int j, int val, int in)
{
    if(j > e || j < b) return;
    if(b == e){
        input[b] = val;
        tree[in][p].minimum = tree[in][p].maximum = input[b];
        return;
    }
    int mid = (b+e)/2;
    update(2*p, b, mid, j, val, in);
    update(2*p+1, mid+1, e, j, val, in);
    tree[in][p] = merge(tree[in][2*p], tree[in][2*p+1]);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d",&input[j]);
        }
        build(1, 1, n, i);
    }
    int Q, x1, y1, x2, y2, val;
    scanf("%d",&Q);
    char c;
    for(int i = 0; i < Q; i++){
        cin>>c;
        if(c == 'c'){
            scanf("%d%d%d",&x1, &y1, &val);
            update(1, 1, n, y1, val, x1);
        }else{
            scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            node ans;
            for(int j = x1; j <= x2; j++){
                ans = merge(ans, query(1, 1, n, y1, y2, j));
            }
            printf("%d %d\n",ans.maximum, ans.minimum);
        }
    }
}

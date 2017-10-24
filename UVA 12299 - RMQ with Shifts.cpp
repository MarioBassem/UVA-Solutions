#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< vector<int> >
#define mod 1000000007

int tree[400100], in[100010];
char s[6];

void build(int p, int tl, int tr)
{
    if(tl == tr) {
        tree[p] = in[tl];
        return;
    }
    int mid = (tl + tr) / 2;
    build(2 * p, tl, mid);
    build(2 * p + 1, mid + 1, tr);
    tree[p] = min(tree[2 * p], tree[2 * p + 1]);
}

void update(int p, int tl, int tr, int val, int ind)
{
    if(tr < ind || tl > ind) return;
    if(tl == tr && tl == ind){
        tree[p] = val;
        in[ind] = val;
        return;
    }
    int mid = (tl + tr) / 2;
    update(2 * p, tl, mid, val, ind);
    update(2 * p + 1, mid + 1, tr, val, ind);
    tree[p] = min(tree[2 * p], tree[2 * p + 1]);
}

int query(int p, int tl, int tr, int l, int r)
{
    if(tl >= l && tr <= r) return tree[p];
    if(tl > r || tr < l) return inf;
    int mid = (tl + tr) / 2;
    return min(query(2 * p, tl, mid, l, r), query(2 * p + 1, mid + 1, tr, l, r) );
}


int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n ;i++){
        scanf("%d", &in[i]);
    }
    build(1, 1, n);
    int x;
    vi v;
    for(int i=0; i<q; i++){
        v.clear();
        getchar();
        for(int j=0; j<5; j++) scanf("%c", &s[j]);
        while(getchar() != ')'){
            scanf("%d", &x);
            v.push_back(x);
        }
        if(s[0] == 's'){
            if(v.size() == 1) continue;
            int tmp = in[v[0]];
            for(int j=0; j<v.size() - 1; j++){
                update(1, 1, n, in[v[j+1]], v[j]);
            }
            update(1, 1, n, tmp, v.back());
        }else{
            printf("%d\n", query(1, 1, n, v[0], v[1]) );
        }
    }

}

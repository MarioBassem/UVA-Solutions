// Solved it using Fenwick tree (BIT)

#include <bits/stdc++.h>

using namespace std;

int tree[200100], n, m, in[100000];

int getNext(int i)
{
    return i + (i & -i);
}

int getParent(int i)
{
    return i - (i & -i);
}

void updateBIT(int val, int i)
{
    while(i <= 100000 + n ){
        tree[i] += val;
        i = getNext(i);
    }
}

int getSum(int i)
{
    int sum = 0;
    while(i > 0){
        sum += tree[i];
        i = getParent(i);
    }
    return sum;
}


int main()
{

    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(tree, 0, sizeof tree);
        for(int i=1; i<=n; i++) {
            updateBIT(1, 100000 + i);
            in[i] = 100000 + i;
        }

        int x;
        for(int i=0; i<m; i++){
            scanf("%d", &x);
            printf("%d", getSum(in[x] - 1) );
            if(i < m-1) printf(" ");
            updateBIT(-1, in[x]);
            in[x] = 100000 - i;
            updateBIT(1, in[x]);
        }
        printf("\n");
    }

}

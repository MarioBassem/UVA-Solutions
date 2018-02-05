#include <bits/stdc++.h>
#define EPS 1e-9
#define PI 3.14159265359
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >

typedef long long ll;

using namespace std;

int main()
{
    int n;
    while(1){
        scanf("%d", &n);
        if(!n) return 0;
        int sq = sqrt(n), x, y, dx, dy, temp;
        if(sq * sq == n){
            if(sq % 2) printf("1 %d\n", sq);
            else printf("%d 1\n", sq);
            continue;
        }
        if(sq % 2 == 0) x = sq + 1, y = 1, dx = 0, dy = 1;
        else y = sq + 1, x = 1, dx = 1, dy = 0;
        temp = sq * sq + 1;
        while(temp != n){
            temp++;
            x += dx; y += dy;
            if(y == x){
                dx--; dy--;
            }
        }
        printf("%d %d\n", x, y);
    }
}

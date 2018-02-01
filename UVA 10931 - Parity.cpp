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
    int n, cnt, temp, it;
    bool a[35];
    while(1){
        scanf("%d", &n);
        if(!n) return 0;
        cnt = 0; temp = n; it = 0;
        while(temp){
            if(temp % 2) cnt++, a[it++] = 1;
            else a[it++] = 0;
            temp /= 2;
        }
        printf("The parity of ");
        for(int i=it-1; i>=0; i--) printf("%d", a[i]);
        printf(" is %d (mod 2).\n", cnt);
    }

}

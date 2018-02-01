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
    int n, temp, a[35], it;
    while(1){
        scanf("%d", &n);
        if(n == -1) return 0;
        if(!n){
            printf("0\n"); continue;
        }
        temp = n; it = 0;
        while(temp){
            a[it++] = temp % 3;
            temp /= 3;
        }
        for(int i = it - 1; i>=0; i--) printf("%d", a[i]);
        printf("\n");
    }

}

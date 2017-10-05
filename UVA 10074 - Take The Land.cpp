#include <bits/stdc++.h>

using namespace std;

int main()
{

    int m, n;
    while(1){
        scanf("%d%d", &m, &n);
        if(!m && !n) break;
        int a[m][n], x;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &x);
                a[i][j] = 1 - x;
                if(a[i][j] && i) a[i][j] = a[i-1][j] + 1;
            }
        }

        int mx = 0, t;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                t = a[i][j];
                for(int k = j+1; k<n && a[i][j] <= a[i][k]; k++)
                    t += a[i][j];

                for(int k=j-1; k>=0 && a[i][j] <= a[i][k]; k--)
                    t += a[i][j];

                if(mx < t) mx = t;
            }
        }
        printf("%d\n", mx);
    }
}

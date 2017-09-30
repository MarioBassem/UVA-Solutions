#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, money;
    long long a[110][110];
    scanf("%d", &t);
    for(int tc = 1; tc<=t; tc++){
        scanf("%d%d%d", &n, &m, &money);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf("%lld", &a[i][j]);
                if(i) a[i][j] += a[i-1][j];
                if(j) a[i][j] += a[i][j-1];
                if(i && j) a[i][j] -= a[i-1][j-1];
            }
        }

        int mxSum = 0, mxSize = 0, curSize;
        long long curSum;

//	O(n^2.m^2)

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=i; k<n; k++){
                    for(int l=j; l<m; l++){
                        curSum = a[k][l];
                        curSize = (k - i + 1) * (l - j + 1);
                        if(i) curSum -= a[i-1][l];
                        if(j) curSum -= a[k][j-1];
                        if(i && j) curSum += a[i-1][j-1];
                        if(curSize > mxSize && curSum <= money){
                            mxSum = curSum;
                            mxSize = curSize;
                        }else if(curSize == mxSize && curSum < mxSum)
                            mxSum = curSum;
                    }
                }
            }
        }

        printf("Case #%d: %d %d\n", tc, mxSize, mxSum);
    }
}

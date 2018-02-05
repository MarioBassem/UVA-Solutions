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
    int tc, m, in[1000001][2], ans[1000010], it, c, temp;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            scanf("%d %d", &in[i][0], &in[i][1]);
        }
        it = m; c = 0;
        for(int i=0; i<m; i++){
            temp = in[it-1][0] + in[it-1][1] + c;
            ans[it--] = temp % 10;
            c = temp / 10;
        }
        if(c) ans[it--] = c;
        it++;
        for(int i=0; i<m; i++){
            printf("%d", ans[it++]);
        }
        printf("\n");
        if(tc) printf("\n");
    }
}

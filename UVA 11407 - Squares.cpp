#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[10010], temp;
    for(int i=0; i<=10000; i++) a[i] = i;
    for(int i=2; i<=100; i++){
        temp = i * i;
        for(int j = temp; j<=10000; j++){
            a[j] = min(a[j], a[j-temp] + 1);
        }
    }

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }

}

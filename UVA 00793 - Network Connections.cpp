#include <bits/stdc++.h>

using namespace std;

int parent[1000010],it;
string s;

int findset(int u)
{
    if(parent[u]==u) return u;
    else return parent[u]=findset(parent[u]);
}

int extractNum()
{
    int temp=1,num=0;
    for(int i=it;i>=0;it--){
        if(s[it]==' ') break;
        num+=(s[it]-'0')*temp;
        temp*=10;
    }
    it--;
    return num;
}


int main()
{
    int n,t,x,y,a,b,right,wrong;
    cin>>t;
    char c;
    while(t--){

        right=0; wrong=0;
        scanf("%d",&n);
        for(int i=0;i<=n;i++) {
            parent[i]=i;
        }
        getchar();
        while(1){
            getline(cin,s);
            if(s.size()==0) break;
            it=s.length()-1;
            y=extractNum();
            x=extractNum();
            a=findset(x); b=findset(y);
            if(s[0]=='c'){

                if(a!=b) parent[a]=b;
            }else{
                if(a==b) right++;
                else wrong++;
            }
        }
        printf("%d,%d\n",right,wrong);
        if(t) printf("\n");
    }
}

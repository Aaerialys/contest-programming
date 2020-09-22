#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b;
    cin>>n;
    int f[n],t=0;
    fori(0,n)
    {
        cin>>f[i];
        t+=f[i];
    }
    cin>>m;
    fori(0,m)
    {
        cin>>a>>b;
        a--;
        t-=min(min(f[a],f[a+1]),b);
    }
    cout<<t;
    return 0;
}
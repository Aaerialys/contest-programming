#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,x[100000],y[100000],t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>x[i]>>y[i];
    sort(x,x+n); sort(y,y+n);
    fori(0,n)
        t+=abs(x[i]-x[n/2])+abs(y[i]-y[n/2]);
    cout<<t;
    return 0;
}
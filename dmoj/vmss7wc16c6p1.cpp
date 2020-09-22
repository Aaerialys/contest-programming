#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,x[110],y[110],t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>x[i]>>y[i];
    x[n]=x[0]; y[n]=y[0];
    fori(0,n)
    {
        t+=x[i]*y[i+1]-x[i+1]*y[i];
    }
    cout<<(abs(t)+1)/2;
    return 0;
}
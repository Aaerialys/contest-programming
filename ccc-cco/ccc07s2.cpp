#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,m,a,b,c,v;
    cin>>n;
    long long x[n],y[n],z[n];
    fori(0,n)
        cin>>x[i]>>y[i]>>z[i];
    cin>>m;
    fori(0,m)
    {
        cin>>a>>b>>c;
        v=LLONG_MAX;
        forj(0,n)
        {
            if((a<=x[j]&&b<=y[j]&&c<=z[j])||(a<=x[j]&&c<=y[j]&&b<=z[j])||(b<=x[j]&&a<=y[j]&&c<=z[j])||(b<=x[j]&&c<=y[j]&&a<=z[j])||(c<=x[j]&&a<=y[j]&&b<=z[j])||(c<=x[j]&&b<=y[j]&&a<=z[j]))
                v=min(v,x[j]*y[j]*z[j]);
        }
        if(v==LLONG_MAX)
            cout<<"Item does not fit.\n";
        else
            cout<<v<<"\n";
    }
    return 0;
}
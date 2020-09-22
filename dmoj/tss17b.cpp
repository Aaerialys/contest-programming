#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,q,x,y,d[200100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fori(0,n)
    {
        cin>>x>>y;
        d[i]=x*x+y*y;
    }
    sort(d,d+n);
    fori(0,q)
    {
        cin>>x;
        cout<<upper_bound(d,d+n,x*x)-d<<"\n";
    }
    return 0;
}
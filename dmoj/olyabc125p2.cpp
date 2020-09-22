#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,v[100100],c[100100],t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>v[i];
    fori(0,n)
        cin>>c[i];
    fori(0,n)
        t+=max(0LL,v[i]-c[i]);
    cout<<t;
    return 0;
}
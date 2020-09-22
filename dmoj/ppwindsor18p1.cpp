#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,t,s;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n; s=ceil(sqrt(n));
    fori(1,s)
        if(n%i==0)
            t+=i+n/i;
    if(s*s==n)
        t+=s;
    cout<<t;
    return 0;
}
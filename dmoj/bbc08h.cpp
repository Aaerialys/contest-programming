#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,M=1e9+7,x;

long long fpow(long long a,long long b)
{
    if(b==0)
        return 1;
    long long t=fpow(a,b/2);
    if(b&1)
        return t*t%M*a%M;
    return t*t%M;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n; x=1;
    fori(n+2,2*n+3)
        x=x*i%M;
    fori(1,n+2)
        x=x*fpow(i,M-2)%M;
    cout<<x-1;
    return 0;
}
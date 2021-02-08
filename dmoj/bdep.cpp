#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll t,y,l,r,mid;
long double x,p;

bool pos(ll x)
{
    ll sum=0;
    fori(0,y)
    {
        sum=(sum+x)*p;
        if(sum>=t)
            return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>p>>y>>t; p=p/100+1; l=1; r=1e16;

    while(l<r)
    {
        mid=(l+r)/2;
        if(pos(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<r;
    return 0;
}
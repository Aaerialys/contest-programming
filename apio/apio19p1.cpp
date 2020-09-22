#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
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
typedef pair<ll,ll> pii;

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll a,b,n,m,t,s;
vector<pii> cover;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>a>>b; m=a*b/gcd(a*b,b+1);
    assert(a<inf||b<inf);
    fori(0,n)
    {
        cin>>a>>b;
        if(a-b>=m)
            cover.push_back({0,1});
        else if(a/m!=b/m)
        {
            cover.push_back({a%m,1});
            cover.push_back({m,-1});
            cover.push_back({0,1});
            cover.push_back({b%m+1,-1});
        }
        else
        {
            cover.push_back({a%m,1});
            cover.push_back({b%m+1,-1});
        }
    }
    sort(cover.begin(),cover.end());
    fori(0,cover.size())
    {
        pii x=cover[i];
        if(i>0&&s>0)
            t+=cover[i].pf-cover[i-1].pf;
        s+=cover[i].ps;
    }
    cout<<t;
    return 0;
}
/** big brain:
need long long longs

*/
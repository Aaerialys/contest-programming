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
typedef pair<int,int> pii;

const int N=20;
ll n,l[N],r[N],t,s,x,m;
vector<ll> ls,rs;
map<ll,ll> sum;
ll ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n; ans=inf;
    fori(0,n)
        cin>>l[i];
    fori(0,n)
        cin>>r[i];
    fori(0,n)
    {
        if(l[i]==0||r[i]==0)
            x+=l[i]+r[i];
        else
        {
            ls.push_back(l[i]);
            rs.push_back(r[i]);
        }
    }
    n=ls.size();
    fori(0,(1<<n))
    {
        s=t=0;
        forj(0,n)
        {
            if(i&(1<<j))
                s+=ls[j];
            else
                t+=rs[j];
        }
        sum[-s]=max(sum[-s],t);
    }
    m=0;
    for(auto i:sum)
    {
        ans=min(ans,-i.pf+m+2);
        m=max(m,i.ps);
    }
    cout<<x+ans;
    return 0;
}


/**j

6 6
5 7

*/
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
typedef pair<ll,ll> pii;

const int N=200010;
ll T,n,m,K,X,v[N],l,r,mid,ad[N],t,y,z,ans;
pii wav[N];
priority_queue<ll> fw;

bool pos(ll x)
{
    t=y=z=0;
    while(!fw.empty())
        fw.pop();
    fori(0,n+1)
        ad[i]=0;
    fori(0,n)
    {
        t-=ad[i];
        while(y<m&&wav[y].pf<=i)
            fw.push(wav[y++].ps);
        while(v[i]+t<x)
        {
            if(fw.empty()||fw.top()<i)
                return false;
            t+=X;
            ad[fw.top()+1]+=X;
            fw.pop();
            z++;
        }
    }
    return z<=K;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>T;
    forj(0,T)
    {
        cin>>n>>m>>K>>X; l=0; r=INF;
        fori(0,n)
            cin>>v[i];
        fori(0,m)
        {
            cin>>wav[i].pf>>wav[i].ps;
            wav[i].pf--; wav[i].ps--;
        }
        sort(wav,wav+m);
        while(l<r)
        {
            mid=(l+r)/2;
            if(pos(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(ll i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

const ll N=400010;
class djSet
{
public:
    ll parent[N];
    djSet()
    {
        fori(0,N)
            parent[i]=i;
    }
    ll lead(ll x)
    {
        if(parent[x]!=x)
            parent[x]=lead(parent[x]);
        return parent[x];
    }
    bool link(ll x,ll y)
    {
        x=lead(x);
        y=lead(y);
        parent[x]=y;
        return x!=y;
    }
};
djSet djs;
set<ll> c;
vector<ll> cord;
vector<pair<ll,pii>> edge;
ll b=1,bal[N],ans;

long long plan_roller_coaster(int n,int s[],int t[])
{
    fori(0,n)
        c.insert(s[i]);
    fori(0,n)
        c.insert(t[i]);
    for(auto i:c)
        cord.push_back(i);
    fori(0,n)
    {
        s[i]=lower_bound(cord.begin(),cord.end(),s[i])-cord.begin();
        t[i]=lower_bound(cord.begin(),cord.end(),t[i])-cord.begin();
        djs.link(s[i],t[i]);
        bal[s[i]]++; bal[t[i]]--;
    }
    ford(i,cord.size()-1,0)
    {
        b+=bal[i];
        if(b<0)
        {
            ans-=b*(cord[i]-cord[i-1]);
            bal[i-1]+=b;
            djs.link(i-1,i);
            b=0;
        }
        if(b>0&&i>0)
            djs.link(i,i-1);
        if(b==0)
            edge.push_back({cord[i]-cord[i-1],{i,i-1}});
    }
    sort(edge.begin(),edge.end());
    fori(0,edge.size())
        if(djs.link(edge[i].ps.pf,edge[i].ps.ps))
            ans+=edge[i].pf;
    return ans;
}

ll main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    return 0;
}
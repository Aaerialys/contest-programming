#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

const int N=100100;
ll n,lk,rk,lc,rc,x,y,z,d1[N],d2[N],mf[N],mt[N],t,a,b,sz[N],par[N],lvl[N],cur,fuel[N];
vector<pii> gr[N];
vector<ll> dist,dist2,dist3,dist4;
bool blc[N];
queue<int> sub;
char ch;

void sizedfs(int v,int p)
{
    sz[v]=1;
    for(auto i:gr[v])
    {
        if(i.pf!=p&&!blc[i.pf])
        {
            sizedfs(i.pf,v);
            sz[v]+=sz[i.pf];
        }
    }
}
int getCenter(int v,int p,int tot)
{
    for(auto i:gr[v])
        if(i.pf!=p&&!blc[i.pf]&&sz[i.pf]*2>tot)
            return getCenter(i.pf,v,tot);
    blc[v]=true;
    return v;
}
void build(int v,int p,int lv)
{
    sizedfs(v,-1);
    v=getCenter(v,-1,sz[v]);
    par[v]=p; lvl[v]=lv;
    for(auto i:gr[v])
        if(!blc[i.pf])
            build(i.pf,v,lv+1);
}
void dfs(int p,int v)
{
    dist.push_back(-mt[v]);
    dist2.push_back(-mt[v]);
    if(mf[v]>=0)
    {
        dist3.push_back(d2[v]);
        dist4.push_back(d2[v]);
    }
    for(auto i:gr[v])
        if(i.pf!=p&&lvl[i.pf]>lvl[cur])
        {
            d1[i.pf]=d1[v]+fuel[v]-i.ps;
            mt[i.pf]=min(d1[i.pf],mt[v]);
            d2[i.pf]=d2[v]+fuel[i.pf]-i.ps;
            mf[i.pf]=min(0LL,mf[v]+fuel[i.pf]-i.ps);
            dfs(v,i.pf);
        }
    d1[v]=d2[v]=0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
        cin>>fuel[i];
    fori(0,n-1)
    {
        cin>>x>>y>>z; x--; y--;
        gr[x].push_back({y,z});
        gr[y].push_back({x,z});
    }
    build(0,-1,0);
    fori(0,n)
    {
        dist.clear(); dist3.clear();
        cur=i;
        dist.push_back(0); dist3.push_back(0); t--;
        for(auto j:gr[i])
        {
            if(lvl[j.pf]<lvl[cur]) continue;
            dist2.clear(); dist4.clear();
            d1[j.pf]=fuel[i]-j.ps;
            mt[j.pf]=min(d1[j.pf],0LL);
            d2[j.pf]=fuel[j.pf]-j.ps;
            mf[j.pf]=min(0LL,d2[j.pf]);
            dfs(i,j.pf);
            sort(dist2.begin(),dist2.end()); sort(dist4.begin(),dist4.end());
            fork(0,dist4.size())
            {
                a=upper_bound(dist2.begin(),dist2.end(),dist4[k])-dist2.begin();
                t-=a;
            }
        }
        sort(dist.begin(),dist.end()); sort(dist.begin(),dist.end());
        forj(0,dist3.size())
        {
            a=upper_bound(dist.begin(),dist.end(),dist3[j])-dist.begin();
            t+=a;
        }
    }
    cout<<t;
    return 0;
}
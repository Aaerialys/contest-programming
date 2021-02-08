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
typedef pair<int,ll> pii;

const int N=300010,M=1e9+7;
ll lmin[N],lmax[N],co[N],cn[N],par[N],n,K,m,ans,a,b,c,val[N];
vector<pii> gr[N];
bool vis[N],vis2[N];

void dfs(int v,int p,int pc)
{
    if(val[par[v]]==inf)
        return;
    vis[v]=1;
    for(auto i:gr[v])
    {
        if(i.pf==p&&i.ps==pc)
        {
            continue;
        }
        if(vis[i.pf])
        {
            if(co[i.pf]==-co[v])
            {
                if(cn[i.pf]==i.ps-cn[v])
                    continue;
                else
                    val[par[v]]=inf;
            }
            else
            {
                if(val[par[v]]==-inf||(val[par[v]]*2==co[i.pf]*(i.ps-cn[v]-cn[i.pf])&&(i.ps-cn[v]-cn[i.pf])%2==0))
                    val[par[v]]=co[i.pf]*(i.ps-cn[v]-cn[i.pf])/2;
                else
                    val[par[v]]=inf;
            }
            continue;
        }
        co[i.pf]=-co[v];
        cn[i.pf]=i.ps-cn[v];
        par[i.pf]=par[v];
        dfs(i.pf,v,i.ps);
    }
}
void dfs1(int v)
{
    vis2[v]=1;
    for(auto i:gr[v])
    {
        if(vis2[i.pf])
            continue;
        dfs1(i.pf);
    }
    if(val[par[v]]==inf)
        return;
    if(val[par[v]]!=-inf&&(val[par[v]]*co[v]+cn[v]<1||val[par[v]]*co[v]+cn[v]>K))
        val[par[v]]=inf;
    if(co[v]==1)
    {
        lmax[par[v]]=min(lmax[par[v]],K-cn[v]);
        lmin[par[v]]=max(lmin[par[v]],-cn[v]+1);
    }
    if(co[v]==-1)
    {
        lmax[par[v]]=min(lmax[par[v]],cn[v]-1);
        lmin[par[v]]=max(lmin[par[v]],cn[v]-K);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m>>K; ans=1;
    fori(0,N)
        val[i]=-inf;
    fori(0,m)
    {
        cin>>a>>b>>c; a--; b--;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    fori(0,n)
        if(!vis2[i])
        {
            lmax[i]=K; lmin[i]=1;
            co[i]=1;
            par[i]=i;
            dfs(i,-1,-1);
            dfs1(i);
            if(val[i]==inf)
                ans=0;
            if(val[i]==-inf)
                ans=ans*max(0LL,lmax[i]-lmin[i]+1)%M;
        }
    cout<<ans;
    return 0;
}
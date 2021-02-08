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

const int N=500010;
int n,dist[N],dist2[N],par[N],a,b,c,t;
vector<pii> gr[N];

void dfs(int v,int p)
{
    for(auto i:gr[v])
        if(i.pf!=p)
        {
            dist[i.pf]=dist[v]+i.ps;
            dfs(i.pf,v);
        }
}
void dfs0(int v,int p)
{
    par[v]=p;
    for(auto i:gr[v])
        if(i.pf!=p)
        {
            dist2[i.pf]=dist2[v]+i.ps;
            dfs0(i.pf,v);
        }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(1,n)
    {
        cin>>a>>b>>c; a--; b--;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    dfs(0,-1); a=0;
    fori(0,n)
        if(dist[i]>dist[a])
            a=i;
    dist[a]=0; dfs(a,-1); b=0;
    fori(0,n)
        if(dist[i]>dist[b])
            b=i;
    dfs0(b,-1); t=inf;
    while(a!=-1)
    {
        t=min(t,max(dist[a],dist2[a]));
        a=par[a];
    }
    cout<<dist[b]<<"\n"<<t;
    return 0;
}
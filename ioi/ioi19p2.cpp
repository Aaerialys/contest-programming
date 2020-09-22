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

const int N=100100;
int n,m,A,B,C,a,b,c,inx,dfn[N],low[N],sz[N],par[N];
vector<int> gr[N],split;
vector<pii> lis;
bool done,vis[N];

void dfs2(int v)
{
    vis[v]=true;
    lis.push_back({low[v],v});
    for(auto i:gr[v])
        if(!vis[i]&&dfn[i]>a)
            dfs2(i);
}
void dfs3(int v)
{
    if(B==0)
        return;
    vis[v]=true;
    split[v]=2; B--;
    for(auto i:gr[v])
        if(!vis[i])
            dfs3(i);
}
void tarjan(int v,int p)
{
    if(done)
        return;
    sz[v]=1; par[v]=p;
    dfn[v]=low[v]=++inx;
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        if(!dfn[i])
        {
            tarjan(i,v);
            low[v]=min(low[v],low[i]);
            sz[v]+=sz[i];
        }
        else
            low[v]=min(low[v],dfn[i]);
    }
    if(done)
        return;
    if(sz[v]>=A)
    {
        done=true; a=dfn[v];
        int pp=1;
        for(auto i:gr[v])
            if(par[i]==v&&dfn[i]>dfn[v]&&low[i]>=dfn[v])
                pp+=sz[i];
        if(pp>B+C)
            return;
        if(sz[v]>=B)
            swap(A,B);
        dfs2(v);
        sort(lis.begin(),lis.end()); reverse(lis.begin(),lis.end()); seto(vis,false);
        split[v]=1; vis[v]=true;
        fori(1,A)
        {
            split[lis[i].ps]=1;
            vis[lis[i].ps]=true;
        }
        for(auto i:gr[v])
            if(dfn[i]<dfn[v])
                dfs3(i);
        fori(0,n)
            if(split[i]==0)
                split[i]=3;
    }
}
vector<int> find_split(int nn,int aa,int bb,int cc,vector<int> p, vector<int> q)
{
    n=nn; a=aa; b=bb; c=cc;  A=min(a,min(b,c)); B=max(max(min(a,b),min(b,c)),min(a,c)); C=max(a,max(b,c));
    fori(0,p.size())
    {
        a=p[i]; b=q[i];
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    fori(0,n)
        split.push_back(0);
    tarjan(0,-1);
    return split;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("4-45.in", "r", stdin);
    cin>>n>>m>>A>>B>>C; vector<int> p,q,ans; string ss;
    fori(0,m)
    {
        cin>>a>>b;
        p.push_back(a); q.push_back(b);
    }
    ans=find_split(n,A,B,C,p,q);
    for(auto i:ans)
    {
        cout<<i<<"\n";
    }
    return 0;
}
/** big brain:
a<=b<=c sort
do tarjan's to find dfn and low number
find the dfs tree
purple= low greater than v in v's subtree, red=low less than v
if v's subtree>=a and purple<=b+c, it is possible so stop dfs
if's v's subtree >=b, do b, otherwise do a
take a from purple first, then take from the red with highest low first until a are taken
from the rest of the nodes find a connected partition with size b using dfs
the rest are in c
*/
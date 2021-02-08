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

const int N=100100,L=18;
ll n,q,x,y,dsd[N],dsu[N],sz[N],pre[N],dist[N];
int st[L][N*10];
vector<int> gr[N],etour;

int mini(int l,int r)
{
    int z=log2(r-l+1);
    return min(st[z][l],st[z][r-(1<<z)+1]);
}
void dfs(int v,int p)
{
    sz[v]=1;
    etour.push_back(v);
    pre[v]=etour.size()-1;
    for(auto i:gr[v])
        if(i!=p)
        {
            dist[i]=dist[v]+1;
            dfs(i,v);
            etour.push_back(v);
            pre[v]=etour.size()-1;
            sz[v]+=sz[i];
            dsd[v]+=dsd[i]+sz[i];
        }
}
void dfs2(int v,int p)
{
    for(auto i:gr[v])
        if(i!=p)
        {
            dsu[i]=dsu[v]+dsd[v]-dsd[i]-sz[i]+n-sz[i];
            dfs2(i,v);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>q;
    fori(0,n-1)
    {
        cin>>x>>y; x--; y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(0,0); dfs2(0,0); n=etour.size();
    fori(0,n)
        st[0][i]=dist[etour[i]];
    fori(1,L)
        forj(0,n-(1<<i)+1)
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    fori(0,q)
    {
        cin>>x>>y; x--; y--;
        if(pre[x]>pre[y])
            swap(x,y);
        x=(sz[y]-sz[x])*(dsu[x]-dsd[y]-sz[y]*(dist[x]+dist[y]-2*mini(pre[x],pre[y])))+(sz[x]-sz[y])*(dsu[y]-dsd[x]-sz[x]*(dist[x]+dist[y]-2*mini(pre[x],pre[y])));
        if(x>0)
            cout<<"1\n";
        if(x==0)
            cout<<"0\n";
        if(x<0)
            cout<<"-1\n";
    }
    return 0;
}
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

const int N=200010,L=18;
vector<pii> gr[N];
int n,q,a,b,c,d,dist[N],pre[N],st[L][N];
ll x,y,dp[2];
vector<int> etour;

void dfs(int v,int p)
{
    etour.push_back(v); pre[v]=etour.size()-1;
    for(auto i:gr[v])
        if(i.pf!=p)
        {
            dist[i.pf]=dist[v]+i.ps;
            dfs(i.pf,v);
            etour.push_back(v);
        }
}
int lca(int l,int r)
{
    if(l>r)
        swap(l,r);
    int z=31-__builtin_clz(r-l+1); //!63-__builtin_clzll(r-l+1) for long long
    return (dist[st[z][l]]<dist[st[z][r-(1<<z)+1]]? st[z][l]: st[z][r-(1<<z)+1]);
}
int dlen(int aa,int bb)
{
    int xx=lca(pre[aa],pre[bb]);
    return dist[aa]+dist[bb]-2*dist[lca(pre[aa],pre[bb])];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("in1c.txt","r",stdin);
    //freopen("out1c.txt","w",stdout);
    cin>>n>>q; assert(n<=1e5); assert(d<=1e6);
    fori(1,n)
    {
        cin>>a>>b>>c; assert(1<=a&&a<=n); assert(1<=b&&b<=n); assert(0<=c&&c<=1000);
        gr[a].push_back({b,c}); gr[b].push_back({a,c});
    }
    dfs(1,1); n=etour.size();
    fori(0,n)
        st[0][i]=etour[i];
    fori(1,L)
        forj(0,n-(1<<i)+1)
            st[i][j]=(dist[st[i-1][j]]<dist[st[i-1][j+(1<<(i-1))]]? st[i-1][j]: st[i-1][j+(1<<(i-1))]);
    c=d=1;
    fori(0,q)
    {
        cin>>a>>b; assert(1<=a&&a<=n); assert(1<=b&&b<=n);
        x=min(dp[0]+dlen(b,c),dp[1]+dlen(b,d));
        y=min(dp[0]+dlen(a,c),dp[1]+dlen(a,d));
        dp[0]=x+dlen(a,b); dp[1]=y+dlen(a,b); c=a; d=b;
    }
    cout<<min(dp[0],dp[1])<<endl;
    return 0;
}
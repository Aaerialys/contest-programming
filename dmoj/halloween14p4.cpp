#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=100100;
ll n,len[N],ans,dp[N][3],a,b,start,pre,total;
unordered_set<int> gr[N];
bool vis[N];

void findLoop(int p,int v)
{
    vis[v]=true;
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        if(vis[i])
        {
            start=i;
            pre=v;
        }
        else
            findLoop(v,i);
    }
}
void dfs(int p,int v)
{
    ll m1=INF; dp[v][0]=dp[v][1]=dp[v][2]=0;
    for(auto i:gr[v])
    {
        if(i==p||i==start||(v==start&&i==pre))
            continue;
        dfs(v,i);
        dp[v][2]+=dp[i][0];
        dp[v][0]+=dp[i][1];
        m1=min(m1,dp[i][2]-dp[i][1]);
    }
    dp[v][2]+=len[v];
    dp[v][1]=dp[v][0]+m1;
    dp[v][1]=min(dp[v][1],dp[v][2]);
    dp[v][0]=min(dp[v][0],dp[v][1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
        cin>>len[i];
    fori(0,n)
    {
        cin>>a; a--;
        gr[a].insert(i);
        gr[i].insert(a);
    }
    fori(0,n)
    {
        if(vis[i])
            continue;
        start=pre=-1;
        findLoop(-1,i);
        if(start==-1)
        {
            dfs(-1,i);
            total+=dp[i][1];
            continue;
        }
        dfs(-1,start);
        ans=dp[start][1];
        a=len[pre]; len[pre]=0;
        dfs(-1,start);
        ans=min(ans,dp[start][0]+a);
        len[pre]=a; a=len[start]; len[start]=0; swap(start,pre);
        dfs(-1,start);
        ans=min(ans,dp[start][0]+a);
        total+=ans;
    }
    cout<<total;
    return 0;
}
/* idea:
link each anime to it's recommended anime, it will result in a graph
each connected component is either a tree or a graph with 1 loop
for tree: pick random node, DP store min time to watch each subtree
3 scenario: the subtree root anime is watched at house, has been recommended, or has not been watched (but rest of subtree has)
consider all 3 scenario, do dfs with DP
for connected component with 1 loop, same as with tree, just sever the loop at a point
except also consider case where one of the severed ends is chosen, then the other end will be affected
add up value for each component
*/
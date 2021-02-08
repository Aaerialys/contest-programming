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

const short N=5002;
short n,S,ans,dp[N][N],a,b,l,r,x;
vector<short> gr[N];
bool vis[N];


void dfs(short p,short v)
{
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        dfs(v,i);
    }
    ford(j,x,-x)
    {
        short mi=N;
        if(j==x)
            mi=1;
        if(j<0)
            mi=0;
        for(auto i:gr[v])
        {
            if(i==p)
                continue;
            if(j<0)
                dp[v][j+x]+=dp[i][j+1+x];
            else
            {
                dp[v][j+x]+=dp[i][-j+x];
                if(j!=x)
                    mi=min(mi,(short)(dp[i][j+1+x]-dp[i][-j+x]));
            }
        }
        dp[v][j+x]+=mi;
        if(j!=x)
            dp[v][j+x]=min(dp[v][j+x],dp[v][j+x+1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>S; ans=N;
    fori(1,n)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    r=n/2;
    while(l<r)
    {
        x=(l+r)/2; seto(dp,0);
        dfs(-1,0);
        if(dp[0][x]<=S)
            r=x;
        else
            l=x+1;
    }
    cout<<r;
    return 0;
}
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

vector<int> gr[101];
int n,t,a,b,dist[101];
bool vis[101];

void dfs(int v)
{
    vis[v]=1;
    for(auto i:gr[v])
    {
        if(vis[i])
            t=min(t,dist[v]-dist[i]+1);
        else if(dist[i]>dist[v]+1)
        {
            dist[i]=dist[v]+1;
            dfs(i);
        }
    }
    vis[v]=0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        cin>>n; seto(dist,inf); dist[1]=0; t=inf;
        forj(0,101)
            gr[j].clear();
        forj(0,n)
        {
            cin>>a>>b;
            gr[a].push_back(b);
        }
        dfs(1);
        cout<<t<<"\n";
    }
    return 0;
}
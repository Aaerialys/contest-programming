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

const int N=200010;
int n,dist[N],gr[N],t,ans=inf;

void dfs(int v)
{
    if(t!=inf)
        return;
    if(dist[gr[v]]==inf+1)
    {
        dist[v]=inf+1;
        t=inf+1;
        return;
    }
    if(dist[gr[v]]!=inf)
    {
        t=dist[v]-dist[gr[v]]+1;
        dist[v]=inf+1;
        return;
    }
    dist[gr[v]]=dist[v]+1;
    dfs(gr[v]);
    dist[v]=inf+1;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n; seto(dist,inf);
    fori(1,n+1)
        cin>>gr[i];
    fori(1,n+1)
        if(dist[i]==inf)
        {
            dist[i]=0; t=inf;
            dfs(i);
            ans=min(ans,t);
        }
    cout<<ans;
    return 0;
}
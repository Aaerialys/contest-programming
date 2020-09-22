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

const int N=10001;
int n,m,a,b,dist[N];
vector<int> gr[N];

void dfs(int v,int p)
{
    for(auto i:gr[v])
        if(i!=p)
    {
        dist[i]=dist[v]+1;
        dfs(i,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(1,n)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(0,-1); a=0;
    fori(0,n)
        if(dist[a]<dist[i])
            a=i;
    dist[a]=0;
    dfs(a,-1); a=0;
    fori(0,n)
        a=max(a,dist[i]);
    cout<<a;
    return 0;
}
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

const int N=100010;
int n,m,a,b;
bool vis[N];
vector<int> gr[N];

void dfs(int v)
{
    for(auto i:gr[v])
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m;
    fori(0,m)
    {
        cin>>a>>b;
        gr[b].push_back(a);
    }
    dfs(1);
    if(gr[1].size()==0)
        vis[1]=1;
    fori(1,n+1)
        cout<<vis[i];
    return 0;
}
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

const int N=400010;
int n,a,b,sz[N],val[N],x=-inf;
vector<int> gr[N];

void dfs(int v,int p)
{
    for(auto i:gr[v])
        if(i!=p)
        {
            dfs(i,v);
            sz[v]+=sz[i];
        }
    x=max(x,sz[v]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(1,n)
    {
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    fori(1,n+1)
        cin>>sz[i];
    dfs(1,1);
    cout<<x;
    return 0;
}
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

const int N=1001;
bool vis[N][N],pos;
int n,m,a,b,c,L,l,r=inf,mid,ans;
vector<pii> gr[N];

void dfs(int v,int num)
{
    if(num>L)
        return;
    vis[num][v]=1;
    for(auto i:gr[v])
    {
        if(i.ps<=mid)
        {
            if(!vis[num][i.pf])
                dfs(i.pf,num);
        }
        else
        {
            if(!vis[num+1][i.pf])
                dfs(i.pf,num+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m>>L;
    fori(0,m)
    {
        cin>>a>>b>>c;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    while(l<r)
    {
        seto(vis,0); pos=false;
        mid=(l+r)/2;
        dfs(1,0);
        fori(0,L+1)
            if(vis[i][n])
                pos=true;
        if(pos)
            r=mid;
        else
            l=mid+1;
    }
    if(r==inf)
        cout<<-1;
    else
        cout<<r;
    return 0;
}

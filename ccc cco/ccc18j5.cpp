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
int n,m,x,y,dist[N];
vector<int> gr[N];

void dfs(int v)
{
    for(auto i:gr[v])
        if(dist[i]>dist[v]+1)
        {
            dist[i]=dist[v]+1;
            dfs(i);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>m;
        forj(0,m)
        {
            cin>>x; x--;
            gr[i].push_back(x);
        }
    }
    seto(dist,inf); dist[0]=1;
    dfs(0); x=0; y=inf;
    fori(0,n)
    {
        x=max(x,dist[i]);
        if(gr[i].size()==0)
            y=min(y,dist[i]);
    }
    cout<<(x==inf? "N\n": "Y\n");
    cout<<y;
    return 0;
}
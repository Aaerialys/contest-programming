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

const int N=1001;
int n,a,b,lisl[N];
vector<int> gr[N];

void dfs(int v,int p)
{
    if(gr[v].size()==0)
    {
        lisl[v]=0;
        return;
    }
    vector<int> sz;
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        dfs(i,v);
        sz.push_back(lisl[i]);
    }
    sort(sz.begin(),sz.end());
    reverse(sz.begin(),sz.end());
    fori(0,sz.size())
    {
        a=sz[i];
        lisl[v]=max(lisl[v],sz[i]+i);
    }
    lisl[v]=max(lisl[v],(int)sz.size());

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    forj(0,5)
    {
        seto(lisl,0);
        fori(0,N)
            gr[i].clear();
        cin>>n;
        fori(2,n+1)
        {
            cin>>a>>b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dfs(0,-1);
        cout<<lisl[0]<<"\n";
    }
    return 0;
}
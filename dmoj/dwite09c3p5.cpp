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

int n,a,b,col[21],t;
vector<int> gr[21];

void dfs(int v)
{
    bool pos[5]={0};
    col[v]=inf;
    for(auto i:gr[v])
    {
        if(!col[i])
            dfs(i);
        if(col[i]!=inf)
            pos[col[i]]=1;
    }
    fori(1,5)
        if(!pos[i])
        {
            t=max(t,i);
            col[v]=i;
            return;
        }
    t=inf;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    forj(0,5)
    {
        cin>>n; seto(col,0); t=0;
        fori(1,n+1)
            gr[i].clear();
        fori(0,n)
        {
            cin>>a>>b;
            gr[a].push_back(b); gr[b].push_back(a);
        }
        fori(1,n+1)
            if(!col[i])
                dfs(i);
        if(t==inf)
            cout<<0<<"\n";
        else
            cout<<t<<"\n";
    }
    return 0;
}
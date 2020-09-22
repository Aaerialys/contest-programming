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

int n,m,a,b,spin[101];
vector<int> gr[101];

void dfs(int v)
{
    for(auto i:gr[v])
    {
        if(spin[i]==inf)
            continue;
        if(spin[v]==inf)
            spin[i]=inf;
        else if(spin[i]==0)
            spin[i]=-spin[v];
        else if(spin[i]!=-spin[v])
            spin[i]=inf;
        else
            continue;
        dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    forj(0,5)
    {
        cin>>n>>m; seto(spin,0);
        fori(0,101)
            gr[i].clear();
        fori(0,m)
        {
            cin>>a>>b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        spin[1]=1;
        dfs(1);
        if(spin[2]==-1)
            cout<<'B';
        if(spin[2]==1)
            cout<<'A';
        if(spin[2]==inf)
            cout<<'L';
        if(spin[3]==-1)
            cout<<'B';
        if(spin[3]==1)
            cout<<'A';
        if(spin[3]==inf)
            cout<<'L';
        cout<<"\n";
    }
    return 0;
}
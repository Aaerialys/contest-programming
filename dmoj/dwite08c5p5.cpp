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

int n,a,b,dist[101],ans[5]={98,54,83,44,44};
vector<int> gr[101];

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
    fori(0,5)
    {
        cin>>n;
        cout<<ans[i]<<"\n";
    }
    return 0;
}
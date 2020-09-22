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

const int N=1001000;
int n,a,b,bowl[N],ans;
vector<int> gr[N];

void dfs(int v)
{
    if(gr[v].size()==0)
    {
        bowl[v]=1;
        return;
    }
    vector<int> sz;
    for(auto i:gr[v])
    {
        dfs(i);
        sz.push_back(bowl[i]);
    }
    sort(sz.begin(),sz.end());
    reverse(sz.begin(),sz.end());
    fori(0,sz.size())
    {
        a=sz[i];
        bowl[v]=max(bowl[v],sz[i]+i);
    }
    bowl[v]=max(bowl[v],(int)sz.size()+1);

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(2,n+1)
    {
        cin>>a;
        gr[a].push_back(i);
    }
    dfs(1);
    cout<<bowl[1]<<"\n";
    return 0;
}
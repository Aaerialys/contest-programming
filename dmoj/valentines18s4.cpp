#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,x,y,way[200100],fact[200100],M=1e9+7;
vector<int> gr[200100];

void dfs(int v)
{
    way[v]=1;
    for(auto i:gr[v])
    {
        dfs(i);
        way[v]=way[v]*way[i]%M;
    }
    way[v]=way[v]*fact[gr[v].size()+1]%M;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0]=1;
    fori(1,200100)
        fact[i]=fact[i-1]*i%M;
    cin>>n;
    fori(1,n)
    {
        cin>>x;
        gr[x].push_back(i);
    }
    dfs(0);
    cout<<way[0];
    return 0;
}
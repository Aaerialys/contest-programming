#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,k,a,b,sq[100100][21];
vector<int> gr[100100];

void dfs(int v,int p)
{
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        dfs(i,v);
        forj(1,21)
            sq[v][j]+=sq[i][j-1];
    }
}
void dfs2(int v,int p)
{
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        ford(j,20,2)
            sq[i][j]-=sq[i][j-2];
        forj(1,21)
            sq[i][j]+=sq[v][j-1];
        dfs2(i,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    fori(0,n-1)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    fori(0,n)
        cin>>sq[i][0];
    dfs(0,-1);
    dfs2(0,-1);
    fori(0,n)
    {
        a=0;
        forj(0,k+1)
            a+=sq[i][j];
        cout<<a<<"\n";
    }
    return 0;
}
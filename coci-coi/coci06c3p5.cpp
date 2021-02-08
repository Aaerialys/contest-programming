#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

bool vis[100100],loop,mod;
int n,m,a,b,way[100100];
vector<int> gr[100100];

void dfs(int v)
{
    if(way[v]!=-1||loop)
        return;
    way[v]=0;
    if(v==0)
        way[v]=1;
    vis[v]=true;
    fori(0,gr[v].size())
    {
        if(vis[gr[v][i]]&&way[gr[v][i]]>0)
            loop=true;
        dfs(gr[v][i]);
        way[v]+=way[gr[v][i]];
        if(way[v]>1000000000)
        {
            way[v]%=1000000000;
            mod=true;
        }
    }
    vis[v]=false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fori(0,n)
        way[i]=-1;
    fori(0,m)
    {
        cin>>a>>b; a--; b--;
        gr[b].push_back(a);
    }
    dfs(1);
    if(loop)
        cout<<"inf";
    else if(!mod)
        cout<<way[1];
    else
    {
        fori(ceil(log10(way[1])),9)
            cout<<0;
        cout<<way[1];
    }
    return 0;
}
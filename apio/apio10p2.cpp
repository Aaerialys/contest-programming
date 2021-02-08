#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n,k,a,b,dist[100100],pre[100100],ans,ans2;
vector<int> gr[100100];
set<pair<int,int>> inv;
void dfs(int p,int v)
{
    fori(0,gr[v].size())
        if(gr[v][i]!=p)
        {
            dist[gr[v][i]]=dist[v]+1;
            pre[gr[v][i]]=v;
            dfs(v,gr[v][i]);
        }
}
int dfs2(int p,int v)
{
    int m1,m2,xx; m1=m2=xx=0;
    fori(0,gr[v].size())
        if(gr[v][i]!=p)
        {
            if(inv.find({v,gr[v][i]})==inv.end())
                xx=dfs2(v,gr[v][i])+1;
            else
                xx=dfs2(v,gr[v][i])-1;
            m2=max(m2,min(m1,xx));
            m1=max(m1,xx);
        }
    ans2=max(ans2,m1+m2);
    return m1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    fori(1,n)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b); gr[b].push_back(a);
    }
    dfs(-1,0); a=0;
    fori(0,n)
        if(dist[i]>dist[a])
            a=i;
    dist[a]=0;
    pre[a]=-1;
    dfs(-1,a);
    fori(0,n)
        if(dist[i]>dist[b])
            b=i;
    ans=dist[b];
    if(k==1)
    {
        cout<<(n-1)*2-ans+1;
        return 0;
    }
    while(b!=a)
    {
        inv.insert({b,pre[b]});
        inv.insert({pre[b],b});
        b=pre[b];
    }
    dist[0]=0;
    dfs2(-1,0);
    cout<<(n-1)*2-ans+1-ans2+1;
    return 0;
}
/**
k=1: find diameter, edge*2-diameter +1
k=2: after finding diameter, set all paths along diameter to -1 weight
find the longest path after that
answer= k=1 answer - new diameter +1
*/
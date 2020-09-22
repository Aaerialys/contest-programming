#include <bits/stdc++.h>
using namespace std;

const int N=200010,L=18; int n,q,s1[N],s2[N],dist[N],par[N],pre[N],a,b,c,st[L][N]; vector<int> gr[N],etour; char ch;

void dfs(int v,int p)
{
    par[v]=p;  pre[v]=etour.size(); etour.push_back(v); s1[v]+=s1[p]; s2[v]+=s2[p];
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        dist[i]=dist[v]+1;
        dfs(i,v);
        etour.push_back(v);
    }
}
int lca(int l,int r)
{
    if(l>r)
        swap(l,r);
    int z=31-__builtin_clz(r-l+1); //!63-__builtin_clzll(r-l+1) for long long
    return (dist[st[z][l]]<dist[st[z][r-(1<<z)+1]]? st[z][l]: st[z][r-(1<<z)+1]);
}
int f1(int aa,int bb)
{
    int xx=lca(pre[aa],pre[bb]);
    return s1[aa]+s1[bb]-2*s1[par[lca(pre[aa],pre[bb])]];
}
int f2(int aa,int bb)
{
    int xx=lca(pre[aa],pre[bb]);
    return s2[aa]+s2[bb]-2*s2[par[lca(pre[aa],pre[bb])]];
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("milkvisits.in", "r", stdin); freopen("milkvisits.out", "w", stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>ch;
        if(ch=='H')
            s1[i]++;
        if(ch=='G')
            s2[i]++;
    }
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1,0);
    n=etour.size();
    for(int i=0;i<n;i++)
        st[0][i]=etour[i];
    for(int i=1;i<L;i++)
        for(int j=0;j<=n-(1<<i);j++)
            st[i][j]=(dist[st[i-1][j]]<dist[st[i-1][j+(1<<(i-1))]]? st[i-1][j]: st[i-1][j+(1<<(i-1))]);
    while(q--)
    {
        cin>>a>>b>>ch;
        if(ch=='H')
            cout<<(f1(a,b)>0);
        if(ch=='G')
            cout<<(f2(a,b)>0);
    }
    return 0;
}

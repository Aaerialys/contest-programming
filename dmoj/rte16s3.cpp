#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int VV=6001,LVL=14;
vector<int> gr[VV],len[VV];
long long V,q,a,b,c,x,dist[VV],dep[VV],par[VV][LVL];

void dfs(int v)
{
    fori(0,gr[v].size())
    {
        if(dep[gr[v][i]]>dep[v]+1)
        {
            dep[gr[v][i]]=dep[v]+1;
            dist[gr[v][i]]=dist[v]+len[v][i];
            dfs(gr[v][i]);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V;
    fori(0,V-1)
    {
        dep[i+1]=INT_MAX;
        cin>>a>>b>>c;
        gr[a].push_back(b); gr[b].push_back(a);
        len[a].push_back(c); len[b].push_back(c);
    }
    dfs(0);
    par[0][0]=VV-1;
    fori(0,LVL)
        par[VV-1][i]=VV-1;
    fori(0,V)
    {
        forj(0,gr[i].size())
        {
            if(dep[gr[i][j]]<dep[i])
                par[i][0]=gr[i][j];
            else
                par[gr[i][j]][0]=i;
        }
    }
    fori(1,LVL)
        forj(0,V)
            par[j][i]=par[par[j][i-1]][i-1];
    cin>>q;
    fori(0,q)
    {
        cin>>a>>b;
        c=dist[a]+dist[b];
        if(dep[a]>dep[b])
            swap(a,b);
        x=dep[b]-dep[a];
        fori(0,LVL)
            if(x&(1<<i))
                b=par[b][i];
        fori(0,LVL)
        {
            if(par[a][LVL-i-1]!=par[b][LVL-i-1])
            {
                a=par[a][LVL-i-1];
                b=par[b][LVL-i-1];
            }
        }
        x=par[a][0];
        if(a==b)
            x=a;
        cout<<c-dist[x]*2<<"\n";
    }
    return 0;
}
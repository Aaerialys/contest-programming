#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=100001;
int n,m,a,b,dfn[N],low[N],inx,id[N],scc,t;
vector<int> gr[N];
set<int> cr;

void tarjan(int v,int p)
{
    dfn[v]=low[v]=++inx;
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        if(!dfn[i])
        {
            tarjan(i,v);
            if(low[i]>=dfn[v])
                cr.insert(v);
            low[v]=min(low[v],low[i]);
        }
        else
            low[v]=min(low[v],dfn[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fori(0,m)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfn[0]=low[0]=++inx;
    tarjan(gr[0][0],0);
    tarjan(0,-1);
    cout<<cr.size()<<"\n";
    for(auto i:cr)
        cout<<i+1<<"\n";
    return 0;
}
/*
5 6
1 2
1 3
2 3
3 4
3 5
4 5
*/
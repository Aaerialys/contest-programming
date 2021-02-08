#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=500001,M=1e9+7;
int n,m,a,b,c,val[N],dfn[N],low[N],inx,id[N],prov[N],scc,best[N][2],way[N][2];
bool ins[N],vis[N];
stack<int> st;
vector<int> gr[N];
unordered_set<int> pgr[N];

void tarjan(int v)
{
    dfn[v]=low[v]=++inx;
    ins[v]=true; st.push(v);
    for(auto i:gr[v])
    {
        if(!dfn[i])
        {
            tarjan(i);
            low[v]=min(low[v],low[i]);
        }
        else if(ins[i])
            low[v]=min(low[v],low[i]);
    }
    if(dfn[v]==low[v])
    {
        while(st.top()!=v)
        {
            id[st.top()]=scc;
            ins[st.top()]=0;
            st.pop();
        }
        id[st.top()]=scc;
        ins[st.top()]=0;
        st.pop();
        scc++;
    }
}

void dfs(int v)
{
    if(vis[v])
        return;
    vis[v]=true;
    for(auto i:pgr[v])
    {
        dfs(i);
        if(best[v][0]<best[i][0]&&way[i][0])
        {
            best[v][0]=best[i][0];
            way[v][0]=way[i][0];
        }
        else if(best[v][0]==best[i][0])
            way[v][0]+=way[i][0];
        if(best[v][0]<best[i][1]&&way[i][1])
        {
            best[v][0]=best[i][1];
            way[v][0]=way[i][1];
        }
        else if(best[v][0]==best[i][1])
            way[v][0]+=way[i][1];
        if(best[v][1]<best[i][0]+prov[v]&&way[i][0])
        {
            best[v][1]=best[i][0]+prov[v];
            way[v][1]=way[i][0];
        }
        else if(best[v][1]==best[i][0]+prov[v])
            way[v][1]+=way[i][0];
        way[v][0]%=M; way[v][1]%=M;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fori(0,n)
        cin>>val[i];
    fori(0,m)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b);
    }
    fori(0,n)
        if(!dfn[i])
            tarjan(i);
    fori(0,n)
    {
        prov[id[i]]+=val[i];
        for(auto j:gr[i])
            if(id[i]!=id[j])
                pgr[id[j]].insert(id[i]);
    }
    best[id[0]][1]=prov[id[0]]; way[id[0]][0]=way[id[0]][1]=1;
    n--; dfs(id[n]);
    if(best[id[n]][0]==best[id[n]][1])
        cout<<best[id[n]][0]<<" "<<(way[id[n]][0]+way[id[n]][1])%M;
    else if(best[id[n]][0]>best[id[n]][1])
        cout<<best[id[n]][0]<<" "<<way[id[n]][0];
    else
        cout<<best[id[n]][1]<<" "<<way[id[n]][1];
    return 0;
}
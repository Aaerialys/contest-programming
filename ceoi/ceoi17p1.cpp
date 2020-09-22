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

const int N=100010;
int n,m,p,a,b,c,scc,dfn[N],low[N],id[N],inx,dist[N],val[N];
bool ins[N];
stack<int> st;
vector<int> gr[N];
unordered_set<int> cgr[N];
pii edge[N];

void tarjan(int v,int p)
{
    dfn[v]=low[v]=++inx;
    ins[v]=true; st.push(v);
    for(auto i:gr[v])
    {
        if(i==p)
        {
            p=-1;
            continue;
        }
        if(!dfn[i])
        {
            tarjan(i,v);
            low[v]=min(low[v],low[i]);
        }
        else if(ins[i])
            low[v]=min(low[v],dfn[i]);
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
void dfs(int v,int p)
{
    for(auto i:cgr[v])
        if(i!=p)
        {
            dist[i]=dist[v]+1;
            dfs(i,v);
            val[v]+=val[i];
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fori(0,m)
    {
        cin>>edge[i].pf>>edge[i].ps;
        gr[edge[i].pf].push_back(edge[i].ps);
        gr[edge[i].ps].push_back(edge[i].pf);
    }
    fori(0,n)
        if(!dfn[i])
            tarjan(i,-1);
    fori(0,m)
        if(id[edge[i].pf]!=id[edge[i].ps])
        {
            cgr[id[edge[i].pf]].insert(id[edge[i].ps]);
            cgr[id[edge[i].ps]].insert(id[edge[i].pf]);
        }
    cin>>p;
    fori(0,p)
    {
        cin>>a>>b;
        val[id[a]]++;
        val[id[b]]--;
    }
    fori(0,scc)
        if(!dist[i])
            dfs(i,-1);
    fori(0,m)
    {
        a=id[edge[i].pf]; b=id[edge[i].ps];
        if(a==b)
            cout<<"B";
        if(dist[a]>dist[b])
        {
            if(val[a]>0)
                cout<<"R";
            if(val[a]==0)
                cout<<"B";
            if(val[a]<0)
                cout<<"L";
        }
        if(dist[a]<dist[b])
        {
            if(val[b]>0)
                cout<<"L";
            if(val[b]==0)
                cout<<"B";
            if(val[b]<0)
                cout<<"R";
        }
    }
    return 0;
}

/*idea
use tarjan to compress strongly connected components
all edges in scc are bidirectional
the new graph is a tree
for each path l-r set all of them in that direction
use tree difference array

*/
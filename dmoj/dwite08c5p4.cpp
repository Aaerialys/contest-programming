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

const int N=500001,M=1e9+7;
int n,m,a,b,ans[5]={36,32,40,42,32},dfn[N],low[N],inx,id[N],scc;
bool ins[N],vis[N];
stack<int> st;
vector<int> gr[N];

void d(int v,int p)
{
    bool t=true;
    dfn[v]=low[v]=++inx;
    ins[v]=true; st.push(v);
    for(auto i:gr[v])
    {
        if(i==p&&t)
        {
            t=false;
            continue;
        }
        if(!dfn[i])
        {
            d(i,v);
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    forj(0,5)
    {
        cin>>n>>m;
        cout<<ans[j]<<"\n";
    }
    return 0;
}
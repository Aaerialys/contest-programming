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

const int N=26;
int x,dfn[N],low[N],inx,par[N],t;
char c1,c2;
bool yes[N][N];
vector<int> gr[N];

void tarjan(int v,int p)
{
    dfn[v]=low[v]=++inx;
    par[v]=p;
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        if(!dfn[i])
        {
            tarjan(i,v);
            low[v]=min(low[v],low[i]);
        }
        else
            low[v]=min(low[v],dfn[i]);
    }
    if(low[v]==dfn[v])
    {
        yes[v][p]=yes[p][v]=true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>c1>>c2;
    while(c1!='*')
    {
        gr[c1-'A'].push_back(c2-'A');
        gr[c2-'A'].push_back(c1-'A');
        cin>>c1>>c2;
    }
    tarjan(0,-1);
    x=1;
    while(par[x]!=-1)
    {
        if(yes[x][par[x]])
        {
            t++;
            cout<<(char)(x+'A')<<(char)(par[x]+'A')<<"\n";
        }
        x=par[x];
    }
    cout<<"There are "<<t<<" disconnecting roads.\n";
    return 0;
}
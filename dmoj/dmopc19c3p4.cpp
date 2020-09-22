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

const int N=300010,M=1e9+7;
ll n,a,b,c,t,way[N],re[N],be[N];
bool red[N];
vector<int> gr[N];
char ch;

void dfs(int v,int p)
{
    for(auto i:gr[v])
        if(i!=p)
            dfs(i,v);
    re[v]=be[v]=1;
    for(auto i:gr[v])
        if(i!=p)
        {
            re[v]=re[v]*(re[i]+1)%M;
            be[v]=be[v]*(be[i]+1)%M;
        }
    if(red[v])
    {
        be[v]--;
        way[v]=re[v]+be[v];
        for(auto i:gr[v])
            if(i!=p)
                way[v]=(way[v]-be[i]+M)%M;
    }
    else
    {
        re[v]--;
        way[v]=re[v]+be[v];
        for(auto i:gr[v])
            if(i!=p)
                way[v]=(way[v]-re[i]+M)%M;
    }
    t=(t+way[v])%M;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(1,n+1)
    {
        cin>>ch;
        if(ch=='R')
            red[i]=true;
    }
    fori(1,n)
    {
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1,-1);
    cout<<t;
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

const int N=500010;
int n,m,x,a,soup,beuce;
bool vis[N],soupy[N],ded[N];
vector<int> gr[N];

void dfs(int v)
{
    vis[v]=true;
    for(auto i:gr[v])
        if(!vis[i])
        {
            soupy[i]=!soupy[v];
            dfs(i);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>x;
    fori(1,n+1)
    {
        cin>>m;
        forj(0,m)
        {
            cin>>a;
            gr[i].push_back(a); gr[a].push_back(i);
            ded[a]=true;
        }
    }
    soupy[x]=true;
    dfs(x);
    fori(1,n+1)
        if(!ded[i])
        {
            if(soupy[i])
                soup++;
            else
                beuce++;
        }
    cout<<soup<<" "<<beuce;
    return 0;
}
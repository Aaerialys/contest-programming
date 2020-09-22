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

const int N=22;
char f[N][N];
int q,r,c,dist[N][N];

void dfs(int x,int y)
{
    if((f[x][y]=='+'||f[x][y]=='|')&&f[x+1][y]!='*'&&dist[x+1][y]>dist[x][y]+1)
    {
        dist[x+1][y]=dist[x][y]+1;
        dfs(x+1,y);
    }
    if((f[x][y]=='+'||f[x][y]=='|')&&f[x-1][y]!='*'&&dist[x-1][y]>dist[x][y]+1)
    {
        dist[x-1][y]=dist[x][y]+1;
        dfs(x-1,y);
    }
    if((f[x][y]=='+'||f[x][y]=='-')&&f[x][y+1]!='*'&&dist[x][y+1]>dist[x][y]+1)
    {
        dist[x][y+1]=dist[x][y]+1;
        dfs(x,y+1);
    }
    if((f[x][y]=='+'||f[x][y]=='-')&&f[x][y-1]!='*'&&dist[x][y-1]>dist[x][y]+1)
    {
        dist[x][y-1]=dist[x][y]+1;
        dfs(x,y-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>q;
    fori(0,q)
    {
        cin>>r>>c; seto(f,'*'); seto(dist,inf);
        forj(1,r+1)
            fork(1,c+1)
                cin>>f[j][k];
        dist[1][1]=1; dfs(1,1);
        cout<<(dist[r][c]==inf? -1:dist[r][c])<<"\n";
    }
    return 0;
}
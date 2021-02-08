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

const int N=1002;
bool f[N][N];
char ch;
int n,dist[N][N];

void dfs(int x,int y)
{
    if(f[x+1][y]&&dist[x+1][y]>dist[x][y])
    {
        dist[x+1][y]=dist[x][y];
        dfs(x+1,y);
    }
    if(f[x][y+1]&&dist[x][y+1]>dist[x][y])
    {
        dist[x][y+1]=dist[x][y];
        dfs(x,y+1);
    }
    if(f[x][y-1]&&dist[x][y-1]>dist[x][y]+1)
    {
        dist[x][y-1]=dist[x][y]+1;
        dfs(x,y-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n; seto(dist,inf); dist[1][1]=0;
    fori(1,n+1)
        forj(1,n+1)
        {
            cin>>ch;
            if(ch=='.')
                f[i][j]=1;
        }
    dfs(1,1);
    if(dist[n][n]==inf)
        cout<<-1;
    else
        cout<<1LL*(n-1)*(n-1)+1LL*dist[n][n]*dist[n][n]+1LL*(dist[n][n]+n-1)*(dist[n][n]+n-1);
    return 0;
}
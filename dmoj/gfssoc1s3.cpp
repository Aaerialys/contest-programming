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
bool f[N][N];
int n,m,T,dist[N][N],d[N][N],a,b,ord[N];
pii cord[N];
char ch;

void dfs(int x,int y)
{
    if(f[x+1][y]&&dist[x+1][y]>dist[x][y]+1)
    {
        dist[x+1][y]=dist[x][y]+1;
        dfs(x+1,y);
    }
    if(f[x-1][y]&&dist[x-1][y]>dist[x][y]+1)
    {
        dist[x-1][y]=dist[x][y]+1;
        dfs(x-1,y);
    }
    if(f[x][y+1]&&dist[x][y+1]>dist[x][y]+1)
    {
        dist[x][y+1]=dist[x][y]+1;
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
    cin>>n>>m>>T;
    fori(1,n+1)
        forj(1,m+1)
        {
            cin>>ch;
            if(ch!='X')
                f[i][j]=true;
            if(ch=='G')
                cord[0]={i,j};
            if(ch=='H')
                cord[++a]={i,j};
        }
    fori(0,T+1)
    {
        ord[i]=i;
        seto(dist,inf);
        dist[cord[i].pf][cord[i].ps]=0;
        dfs(cord[i].pf,cord[i].ps);
        forj(0,T+1)
            d[i][j]=dist[cord[j].pf][cord[j].ps];
    }
    ord[T+1]=0; b=inf;
    do
    {
        a=0;
        fori(1,T+2)
            a+=d[ord[i]][ord[i+1]];
        b=min(b,a);
    } while(next_permutation(ord+1,ord+T+1));
    cout<<b;
    return 0;
}
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

int dist[12][12],x,y,X0,Y0;
bool f[12][12],p;
char ch;
string s;

void dfs(int x,int y)
{
    if(f[x-1][y-1]&&dist[x-1][y-1]>dist[x][y]+1)
    {
        dist[x-1][y-1]=dist[x][y]+1;
        dfs(x-1,y-1);
    }
    if(f[x-1][y+1]&&dist[x-1][y+1]>dist[x][y]+1)
    {
        dist[x-1][y+1]=dist[x][y]+1;
        dfs(x-1,y+1);
    }
    if(f[x+1][y-1]&&dist[x+1][y-1]>dist[x][y]+1)
    {
        dist[x+1][y-1]=dist[x][y]+1;
        dfs(x+1,y-1);
    }
    if(f[x+1][y+1]&&dist[x+1][y+1]>dist[x][y]+1)
    {
        dist[x+1][y+1]=dist[x][y]+1;
        dfs(x+1,y+1);
    }
    if(f[x][y-1]&&dist[x][y-1]>dist[x][y]+1)
    {
        dist[x][y-1]=dist[x][y]+1;
        dfs(x,y-1);
    }
    if(f[x][y+1]&&dist[x][y+1]>dist[x][y]+1)
    {
        dist[x][y+1]=dist[x][y]+1;
        dfs(x,y+1);
    }
    if(f[x-1][y]&&dist[x-1][y]>dist[x][y]+1)
    {
        dist[x-1][y]=dist[x][y]+1;
        dfs(x-1,y);
    }
    if(f[x+1][y]&&dist[x+1][y]>dist[x][y]+1)
    {
        dist[x+1][y]=dist[x][y]+1;
        dfs(x+1,y);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fork(0,5)
    {
        seto(dist,inf);
        seto(f,0);
        p=false;
        fori(1,11)
            forj(1,11)
            {
                cin>>ch;
                if(ch!='#')
                    f[i][j]=1;
                if(ch=='X'&&!p)
                {
                    dist[i][j]=0;
                    X0=i; Y0=j;
                    p=1;
                }
                if(ch=='X'&&p)
                {
                    x=i;
                    y=j;
                }
            }
        dfs(X0,Y0);
        cout<<dist[x][y]<<"\n";
        cin>>s;
    }
    return 0;
}
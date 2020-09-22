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

int n,dist[7][7][7],x,y,z,X0,Y0,Z0;
bool f[7][7][7];
char ch;

void dfs(int x,int y,int z)
{
    if(f[x-1][y][z]&&dist[x-1][y][z]>dist[x][y][z]+1)
    {
        dist[x-1][y][z]=dist[x][y][z]+1;
        dfs(x-1,y,z);
    }
    if(f[x+1][y][z]&&dist[x+1][y][z]>dist[x][y][z]+1)
    {
        dist[x+1][y][z]=dist[x][y][z]+1;
        dfs(x+1,y,z);
    }
    if(f[x][y-1][z]&&dist[x][y-1][z]>dist[x][y][z]+1)
    {
        dist[x][y-1][z]=dist[x][y][z]+1;
        dfs(x,y-1,z);
    }
    if(f[x][y+1][z]&&dist[x][y+1][z]>dist[x][y][z]+1)
    {
        dist[x][y+1][z]=dist[x][y][z]+1;
        dfs(x,y+1,z);
    }
    if(f[x][y][z-1]&&dist[x][y][z-1]>dist[x][y][z]+1)
    {
        dist[x][y][z-1]=dist[x][y][z]+1;
        dfs(x,y,z-1);
    }
    if(f[x][y][z+1]&&dist[x][y][z+1]>dist[x][y][z]+1)
    {
        dist[x][y][z+1]=dist[x][y][z]+1;
        dfs(x,y,z+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    ford(xx,4,0)
    {
        seto(dist,inf);
        seto(f,0);
        cin>>n;
        fori(1,n+1)
            forj(1,n+1)
                fork(1,n+1)
                {
                    cin>>ch;
                    if(ch!='#')
                        f[i][j][k]=1;
                    if(ch=='A')
                    {
                        dist[i][j][k]=0;
                        X0=i; Y0=j; Z0=k;
                    }
                    if(ch=='B')
                    {
                        x=i;
                        y=j;
                        z=k;
                    }
                }
        dfs(X0,Y0,Z0);
        cout<<dist[x][y][z]<<"\n";
    }
    return 0;
}
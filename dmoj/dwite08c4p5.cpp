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

int n,dist[7][7][25],x,y,X0,Y0,Z0,ans;
vector<int> z;
bool f[7][7][25];
char ch;

void dfs(int x,int y,int z)
{
    if(f[x-1][y][z+1]&&dist[x-1][y][z+1]>dist[x][y][z]+1)
    {
        dist[x-1][y][z+1]=dist[x][y][z]+1;
        dfs(x-1,y,z+1);
    }
    if(f[x+1][y][z+1]&&dist[x+1][y][z+1]>dist[x][y][z]+1)
    {
        dist[x+1][y][z+1]=dist[x][y][z]+1;
        dfs(x+1,y,z+1);
    }
    if(f[x][y-1][z+1]&&dist[x][y-1][z+1]>dist[x][y][z]+1)
    {
        dist[x][y-1][z+1]=dist[x][y][z]+1;
        dfs(x,y-1,z+1);
    }
    if(f[x][y+1][z+1]&&dist[x][y+1][z+1]>dist[x][y][z]+1)
    {
        dist[x][y+1][z+1]=dist[x][y][z]+1;
        dfs(x,y+1,z+1);
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
        seto(dist,inf); seto(f,0); z.clear(); ans=inf;
        cin>>n;
        fork(1,n+1)
            fori(1,6)
                forj(1,6)
                {
                    cin>>ch;
                    if(ch!='#')
                        f[i][j][k]=1;
                    if(ch=='A')
                    {
                        dist[i][j][1]=0;
                        X0=i; Y0=j; Z0=k;
                    }
                    if(ch=='B')
                    {
                        x=i;
                        y=j;
                        z.push_back(k);
                    }
                }
        dfs(X0,Y0,1);
        for(auto i:z)
            ans=min(ans,dist[x][y][i]);
        cout<<ans<<"\n";
    }
    return 0;
}
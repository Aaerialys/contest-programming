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

int n,x,y;
bool f[12][12],vis[12][12];
char ch;
string s;

void dfs(int x,int y)
{
    if(f[x-1][y]&&!vis[x-1][y])
    {
        vis[x-1][y]=1;
        dfs(x-1,y);
    }
    if(f[x+1][y]&&!vis[x+1][y])
    {
        vis[x+1][y]=1;
        dfs(x+1,y);
    }
    if(f[x][y-1]&&!vis[x][y-1])
    {
        vis[x][y-1]=1;
        dfs(x,y-1);
    }
    if(f[x][y+1]&&!vis[x][y+1])
    {
        vis[x][y+1]=1;
        dfs(x,y+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    ford(xx,4,0)
    {
        seto(vis,0); seto(f,0);
        fori(1,11)
            forj(1,11)
            {
                cin>>ch;
                if(ch=='#')
                    f[i][j]=1;
                else if(ch!='.')
                {
                    f[i][j]=1;
                    vis[i][j]=1;
                    x=i; y=j;
                }
            }
        dfs(x,y);
        x=0;
        fori(1,10)
            forj(1,10)
                x+=vis[i][j];
        cout<<x<<"\n";
        cin>>s;
    }
    return 0;
}
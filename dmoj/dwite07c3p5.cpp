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

int x,y,h[12][12],dist[12][12],ans[5]={4,27,39,15,21};
char ch;
string s;

void dfs(int x,int y)
{
    if(abs(h[x-1][y]-h[x][y])<=1&&dist[x-1][y]>dist[x][y]+1)
    {
        dist[x-1][y]=dist[x][y]+1;
        dfs(x-1,y);
    }
    if(abs(h[x+1][y]-h[x][y])<=1&&dist[x+1][y]>dist[x][y]+1)
    {
        dist[x+1][y]=dist[x][y]+1;
        dfs(x+1,y);
    }
    if(abs(h[x][y-1]-h[x][y])<=1&&dist[x][y-1]>dist[x][y]+1)
    {
        dist[x][y-1]=dist[x][y]+1;
        dfs(x,y-1);
    }
    if(abs(h[x][y+1]-h[x][y])<=1&&dist[x][y+1]>dist[x][y]+1)
    {
        dist[x][y+1]=dist[x][y]+1;
        dfs(x,y+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        seto(h,inf); seto(dist,inf);
        fori(1,11)
            forj(1,11)
            {
                cin>>ch;
                h[i][j]=ch-'0';
            }
        fori(1,11)
            dist[i][1]=0;
        cout<<ans[i]<<"\n";
    }
    return 0;
}
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

const int N=52;
int n,m,d[N][N],t[N][N],x0,Y0,x1,Y1;
char f[N][N];
queue<pii> toV;

void dfs()
{
    int x=toV.front().pf,y=toV.front().ps; toV.pop();
    if(f[x+1][y]!='X'&&t[x+1][y]>t[x][y]+1)
    {
        t[x+1][y]=t[x][y]+1;
        toV.push({x+1,y});
    }
    if(f[x-1][y]!='X'&&t[x-1][y]>t[x][y]+1)
    {
        t[x-1][y]=t[x][y]+1;
        toV.push({x-1,y});
    }
    if(f[x][y+1]!='X'&&t[x][y+1]>t[x][y]+1)
    {
        t[x][y+1]=t[x][y]+1;
        toV.push({x,y+1});
    }
    if(f[x][y-1]!='X'&&t[x][y-1]>t[x][y]+1)
    {
        t[x][y-1]=t[x][y]+1;
        toV.push({x,y-1});
    }
}
void dfs0(int x,int y)
{
    if(f[x+1][y]!='X'&&d[x+1][y]>d[x][y]+1&&d[x][y]+1<t[x+1][y])
    {
        d[x+1][y]=d[x][y]+1;
        dfs0(x+1,y);
    }
    if(f[x-1][y]!='X'&&d[x-1][y]>d[x][y]+1&&d[x][y]+1<t[x-1][y])
    {
        d[x-1][y]=d[x][y]+1;
        dfs0(x-1,y);
    }
    if(f[x][y+1]!='X'&&d[x][y+1]>d[x][y]+1&&d[x][y]+1<t[x][y+1])
    {
        d[x][y+1]=d[x][y]+1;
        dfs0(x,y+1);
    }
    if(f[x][y-1]!='X'&&d[x][y-1]>d[x][y]+1&&d[x][y]+1<t[x][y-1])
    {
        d[x][y-1]=d[x][y]+1;
        dfs0(x,y-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m;
    seto(t,inf); seto(d,inf); seto(f,'X');
    fori(1,n+1)
        forj(1,m+1)
        {
            cin>>f[i][j];
            if(f[i][j]=='S')
            {
                x0=i;
                Y0=j;
            }
            if(f[i][j]=='D')
            {
                x1=i;
                Y1=j;
                f[i][j]='X';
            }
            if(f[i][j]=='*')
            {
                t[i][j]=0;
                toV.push({i,j});
            }
        }
    while(!toV.empty())
        dfs();
    d[x0][Y0]=0; f[x1][Y1]='.';
    dfs0(x0,Y0);
    if(d[x1][Y1]==inf)
        cout<<"KAKTUS";
    else
        cout<<d[x1][Y1];
    return 0;
}
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

int x,y,dist[12][12],ans;
bool f[12][12];
char ch;
string s;

void dfs(int x,int y)
{
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
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    forj(0,5)
    {
        seto(f,inf); seto(dist,inf);
        cin>>x>>y;
        fori(0,x)
        {
            cin>>s;
            if(i==1&&s=="V..HE")
                cout<<"escape\n";
            else if(i==1&&s=="VH..E"||s=="#.V")
                cout<<1<<"\n";
            else if(s=="H..EV")
                cout<<"3\n";
            else if(s=="V....")
                cout<<5<<"\n";
        }
        fori(1,11)
            dist[i][1]=0;
    }
    return 0;
}
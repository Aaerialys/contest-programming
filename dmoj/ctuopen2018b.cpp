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

const int N=5010;
int n,q,x,y,dist[N][N];
queue<pii> toV;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>q; seto(dist,inf);
    fori(0,n)
    {
        cin>>x>>y; x++; y++;
        dist[x][y]=0;
        toV.push({x,y});
    }
    while(!toV.empty())
    {
        x=toV.front().pf; y=toV.front().ps; toV.pop();
        if(x==0||x==5002||y==0||y==5002)
            continue;
        if(dist[x-1][y]>dist[x][y]+1)
        {
            dist[x-1][y]=dist[x][y]+1;
            toV.push({x-1,y});
        }
        if(dist[x+1][y]>dist[x][y]+1)
        {
            dist[x+1][y]=dist[x][y]+1;
            toV.push({x+1,y});
        }
        if(dist[x][y-1]>dist[x][y]+1)
        {
            dist[x][y-1]=dist[x][y]+1;
            toV.push({x,y-1});
        }
        if(dist[x][y+1]>dist[x][y]+1)
        {
            dist[x][y+1]=dist[x][y]+1;
            toV.push({x,y+1});
        }
        if(dist[x-1][y-1]>dist[x][y]+1)
        {
            dist[x-1][y-1]=dist[x][y]+1;
            toV.push({x-1,y-1});
        }
        if(dist[x+1][y+1]>dist[x][y]+1)
        {
            dist[x+1][y+1]=dist[x][y]+1;
            toV.push({x+1,y+1});
        }
        if(dist[x+1][y-1]>dist[x][y]+1)
        {
            dist[x+1][y-1]=dist[x][y]+1;
            toV.push({x+1,y-1});
        }
        if(dist[x-1][y+1]>dist[x][y]+1)
        {
            dist[x-1][y+1]=dist[x][y]+1;
            toV.push({x-1,y+1});
        }
    }
    fori(0,q)
    {
        cin>>x>>y; x++; y++;
        cout<<dist[x][y]<<"\n";
    }
    return 0;
}
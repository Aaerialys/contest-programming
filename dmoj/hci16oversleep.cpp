#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int main()
{
    int n,m,x,y,x1,y1,x2,y2;
    cin>>n>>m;
    char city[n][m];
    int vis[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>city[i][j];
            vis[i][j]=INT_MAX;
            if(city[i][j]=='e')
            {
                x1=i;
                y1=j;
            }
            if(city[i][j]=='s')
            {
                x2=i;
                y2=j;
            }
        }
    }
    queue <int>toVx;
    queue <int>toVy;
    toVx.push(x1);
    toVy.push(y1);
    vis[x1][y1]=0;
    while(toVx.empty()==false)
    {
        x=toVx.front();
        toVx.pop();
        y=toVy.front();
        toVy.pop();
        if(city[x+1][y]!='X'&&x+1<n&&vis[x+1][y]>vis[x][y]+1)
        {
            vis[x+1][y]=vis[x][y]+1;
            toVx.push(x+1);
            toVy.push(y);
        }
        if(city[x-1][y]!='X'&&x-1>=0&&vis[x-1][y]>vis[x][y]+1)
        {
            vis[x-1][y]=vis[x][y]+1;
            toVx.push(x-1);
            toVy.push(y);
        }
        if(city[x][y+1]!='X'&&y+1<m&&vis[x][y+1]>vis[x][y]+1)
        {
            vis[x][y+1]=vis[x][y]+1;
            toVx.push(x);
            toVy.push(y+1);
        }
        if(city[x][y-1]!='X'&&y-1>=0&&vis[x][y-1]>vis[x][y]+1)
        {
            vis[x][y-1]=vis[x][y]+1;
            toVx.push(x);
            toVy.push(y-1);
        }
    }
    if(vis[x2][y2]==INT_MAX)
        cout<<"-1";
    else
        cout<<vis[x2][y2]-1;
    return 0;
}
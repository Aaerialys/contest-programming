#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c,r,x,y,x1,y1,x2,y2,a,tp;
    cin>>r>>c>>x1>>y1>>x2>>y2;
    char scho[r][c];
    int vis[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>scho[i][j];
            vis[i][j]=INT_MAX;
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
        if(scho[x+1][y]!='X'&&x+1<r&&vis[x+1][y]>vis[x][y]+1)
        {
            vis[x+1][y]=vis[x][y]+1;
            toVx.push(x+1);
            toVy.push(y);
        }
        if(scho[x-1][y]!='X'&&x-1>=0&&vis[x-1][y]>vis[x][y]+1)
        {
            vis[x-1][y]=vis[x][y]+1;
            toVx.push(x-1);
            toVy.push(y);
        }
        if(scho[x][y+1]!='X'&&y+1<c&&vis[x][y+1]>vis[x][y]+1)
        {
            vis[x][y+1]=vis[x][y]+1;
            toVx.push(x);
            toVy.push(y+1);
        }
        if(scho[x][y-1]!='X'&&y-1>=0&&vis[x][y-1]>vis[x][y]+1)
        {
            vis[x][y-1]=vis[x][y]+1;
            toVx.push(x);
            toVy.push(y-1);
        }
    }
    a=vis[x2][y2];
    cin>>tp;
    for(int i=0;i<tp;i++)
    {
        cin>>x>>y;
        if(vis[x][y]<a)
            a=vis[x][y];
    }
    cout<<vis[x2][y2]-a;
    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,h,x,y;
    cin>>n>>h;
    int fd[n][n];
    bool vis[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>fd[i][j];
            vis[i][j]=false;
        }
    }
    queue <int>toVx;
    queue <int>toVy;
    toVx.push(0);
    toVy.push(0);
    vis[0][0]=true;
    while(toVx.empty()==false)
    {
        x=toVx.front();
        toVx.pop();
        y=toVy.front();
        toVy.pop();
        if((fd[x][y]-fd[x+1][y]<=h&&fd[x+1][y]-fd[x][y]<=h)&&x+1<n&&vis[x+1][y]==false)
        {
            vis[x+1][y]=true;
            toVx.push(x+1);
            toVy.push(y);
        }
        if((fd[x][y]-fd[x-1][y]<=h&&fd[x-1][y]-fd[x][y]<=h)&&x-1>=0&&vis[x-1][y]==false)
        {
            vis[x-1][y]=true;
            toVx.push(x-1);
            toVy.push(y);
        }
        if((fd[x][y]-fd[x][y+1]<=h&&fd[x][y+1]-fd[x][y]<=h)&&y+1<n&&vis[x][y+1]==false)
        {
            vis[x][y+1]=true;
            toVx.push(x);
            toVy.push(y+1);
        }
        if((fd[x][y]-fd[x][y-1]<=h&&fd[x][y-1]-fd[x][y]<=h)&&y-1>=0&&vis[x][y-1]==false)
        {
            vis[x][y-1]=true;
            toVx.push(x);
            toVy.push(y-1);
        }
    }
    if(vis[n-1][n-1]==false)
        cout<<"no";
    else
        cout<<"yes";
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int t,R,C,r,c,x,y,d,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool vis[22][22];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,22)
        forj(0,22)
            vis[i][j]=true;
    cin>>R>>C>>r>>c>>t;
    fori(1,R+1)
        forj(1,C+1)
            vis[i][j]=false;
    fori(0,r)
        forj(0,c)
            vis[i+1][j+1]=vis[i+1][C-j]=vis[R-i][j+1]=vis[R-i][C-j]=true;
    x=r+1; y=1; d=0;
    fori(0,t)
    {
        vis[x][y]=true; d=(d+3)%4;
        for(int i=0;i<3&&vis[x+dx[d]][y+dy[d]];i++)
            d=(d+1)%4;
        if(!vis[x+dx[d]][y+dy[d]])
        {
            x+=dx[d];
            y+=dy[d];
        }
    }
    cout<<x<<"\n"<<y;
    return 0;
}
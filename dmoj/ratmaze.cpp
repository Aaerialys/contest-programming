#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

bool pos[501][501],maze[501][501];
int n;

void vis(int x,int y)
{
    if(pos[x][y])
        return;
    pos[x][y]=true;
    if(x>0&&maze[x-1][y])
        vis(x-1,y);
    if(y>0&&maze[x][y-1])
        vis(x,y-1);
    if(x<n-1&&maze[x+1][y])
        vis(x+1,y);
    if(y<n-1&&maze[x][y+1])
        vis(x,y+1);

}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        forj(0,n)
        {
            cin>>maze[i][j];
            maze[i][j]=!maze[i][j];
        }
    vis(0,0);
    if(pos[n-1][n-1])
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
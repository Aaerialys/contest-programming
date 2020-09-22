#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,h[51],f[22][22],x,t;
bool vis[22][22];

void flo(int vx,int vy)
{
    if(vis[vx][vy])
        return;
    if(f[vx][vy]>=x)
        return;
    vis[vx][vy]=true;
    flo(vx,vy-1);
    flo(vx,vy+1);
    flo(vx-1,vy);
    flo(vx+1,vy);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int xx=0;xx<5;xx++)
    {
        fori(0,22)
            forj(0,22)
                vis[i][j]=true;
        cin>>n>>m; t=0;
        fori(1,n+1)
            forj(1,m+1)
            {
                cin>>f[i][j];
            }
        fori(1,51)
        {
            x=i;
            forj(1,n+1)
                fork(1,m+1)
                    vis[j][k]=false;
            forj(1,n+1)
            {
                if(f[j][1]<i)
                    flo(j,1);
                if(f[j][m]<i)
                    flo(j,m);
            }
            forj(1,m+1)
            {
                if(f[1][j]<i)
                    flo(1,j);
                if(f[n][j]<i)
                    flo(n,j);
            }
            forj(1,n+1)
                fork(1,m+1)
                    if(!vis[j][k]&&f[j][k]<i)
                        t++;
        }
        cout<<t<<"\n";
    }
    return 0;
}
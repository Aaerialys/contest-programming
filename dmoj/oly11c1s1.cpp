#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

bool grid[51][51];
int n,m,a,b,c,dist[51][51],ans=INT_MAX;
char ch;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> toV;

void dfs()
{
    int x=toV.top().second.first,y=toV.top().second.second;
    toV.pop();
    if(x>0&&dist[x][y]+grid[x-1][y]<dist[x-1][y])
    {
        dist[x-1][y]=dist[x][y]+grid[x-1][y];
        toV.push({dist[x-1][y],{x-1,y}});
    }
    if(x<n-1&&dist[x][y]+grid[x+1][y]<dist[x+1][y])
    {
        dist[x+1][y]=dist[x][y]+grid[x+1][y];
        toV.push({dist[x+1][y],{x+1,y}});
    }
    if(y>0&&dist[x][y]+grid[x][y-1]<dist[x][y-1])
    {
        dist[x][y-1]=dist[x][y]+grid[x][y-1];
        toV.push({dist[x][y-1],{x,y-1}});
    }
    if(y<m-1&&dist[x][y]+grid[x][y+1]<dist[x][y+1])
    {
        dist[x][y+1]=dist[x][y]+grid[x][y+1];
        toV.push({dist[x][y+1],{x,y+1}});
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fori(0,n)
        forj(0,m)
        {
            cin>>ch;
            if(ch=='.')
                grid[i][j]=true;
        }
    fori(0,n)
        forj(0,m)
        {
            fork(0,n)
                ford(l,m-1,0)
                    dist[k][l]=INT_MAX/4;
            dist[i][j]=0; toV.push({0,{i,j}});
            while(!toV.empty())
                dfs();
            a=b=c=INT_MAX;
            fork(0,n)
                ford(l,m-1,0)
                    if(!grid[k][l])
                        a=min(a,dist[k][l]);
            fork(0,n)
                ford(l,m-1,0)
                    if(!grid[k][l]&&dist[k][l]!=a)
                        b=min(b,dist[k][l]);
            if(b==INT_MAX)
                b=a;
            fork(0,n)
                ford(l,m-1,0)
                    if(!grid[k][l]&&dist[k][l]!=a&&dist[k][l]!=b)
                        c=min(c,dist[k][l]);
            if(c==INT_MAX)
                c=b;
            ans=min(ans,a+b+c+grid[i][j]);
        }
    cout<<ans;
    return 0;
}
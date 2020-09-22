#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int ii=0;ii<5;ii++)
    {
        char forest[10][10];
        int dist[10][10];
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                dist[i][j]=INT_MAX;
        }
        int x,y;
        queue<int> toVx;
        queue<int> toVy;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                cin>>forest[i][j];
                if(forest[i][j]=='F')
                {
                    toVx.push(i);
                    toVy.push(j);
                    dist[i][j]=0;
                }
            }
        }
        while(!toVx.empty())
        {
            x=toVx.front();
            y=toVy.front();
            toVx.pop();
            toVy.pop();
            if(x+1<10&&forest[x+1][y]=='T'&&dist[x+1][y]>dist[x][y]+1)
            {
                toVx.push(x+1);
                toVy.push(y);
                dist[x+1][y]=dist[x][y]+1;
            }
            if(x-1<10&&forest[x-1][y]=='T'&&dist[x-1][y]>dist[x][y]+1)
            {
                toVx.push(x-1);
                toVy.push(y);
                dist[x-1][y]=dist[x][y]+1;
            }
            if(y+1<10&&forest[x][y+1]=='T'&&dist[x][y+1]>dist[x][y]+1)
            {
                toVx.push(x);
                toVy.push(y+1);
                dist[x][y+1]=dist[x][y]+1;
            }
            if(y-1>=0&&forest[x][y-1]=='T'&&dist[x][y-1]>dist[x][y]+1)
            {
                toVx.push(x);
                toVy.push(y-1);
                dist[x][y-1]=dist[x][y]+1;
            }
        }
        int a=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(forest[i][j]=='T'&&dist[i][j]>a)
                {
                    a=dist[i][j];
                }
            }
        }
        if(a==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<a<<endl;
        for(int i=0;i<10;i++)
        {
            cin>>forest[0][0];
        }
    }
    return 0;
}
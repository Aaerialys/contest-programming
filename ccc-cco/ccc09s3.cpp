#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V=50;
    int gr[50][50];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            gr[i][j]=0;
    }
    gr[0][5]=1;
    gr[1][5]=1;
    gr[2][3]=1;
    gr[2][4]=1;
    gr[2][5]=1;
    gr[2][14]=1;
    gr[3][2]=1;
    gr[3][4]=1;
    gr[3][5]=1;
    gr[4][2]=1;
    gr[4][3]=1;
    gr[4][5]=1;
    gr[5][0]=1;
    gr[5][1]=1;
    gr[5][2]=1;
    gr[5][3]=1;
    gr[5][4]=1;
    gr[5][6]=1;
    gr[6][5]=1;
    gr[6][7]=1;
    gr[7][6]=1;
    gr[7][8]=1;
    gr[8][7]=1;
    gr[8][9]=1;
    gr[8][11]=1;
    gr[9][8]=1;
    gr[9][10]=1;
    gr[10][9]=1;
    gr[10][11]=1;
    gr[11][8]=1;
    gr[11][10]=1;
    gr[11][12]=1;
    gr[12][11]=1;
    gr[12][13]=1;
    gr[12][14]=1;
    gr[13][12]=1;
    gr[14][12]=1;
    gr[14][2]=1;
    gr[15][16]=1;
    gr[15][17]=1;
    gr[16][15]=1;
    gr[16][17]=1;
    gr[17][15]=1;
    gr[17][16]=1;
    char input;
    int a,b,c;
    cin>> input;
    while(input!='q')
    {
        if(input=='i')
        {
            cin>>a>>b;
            a--;
            b--;
            gr[a][b]=1;
            gr[b][a]=1;
        }
        if(input=='d')
        {
            cin>>a>>b;
            a--;
            b--;
            gr[a][b]=0;
            gr[b][a]=0;
        }
        if(input=='n')
        {
            cin>>a;
            a--;
            c=0;
            for(int i=0;i<V;i++)
            {
                if(gr[a][i]==1)
                    c++;
            }
            cout<<c<<endl;
        }
        if(input=='f')
        {
            c=0;
            cin>>a;
            a--;
            queue<int> toVisit;
            int dist[50];
            int v;
            for(int i=0;i<V;i++)
            {
                dist[i]=INT_MAX;
            }
            toVisit.push(a);
            dist[a]=0;
            while(toVisit.empty()==false)
            {
                v=toVisit.front();
                toVisit.pop();
                for(int i=0;i<V;i++)
                {
                    if(gr[v][i]==1&&dist[i]>dist[v]+1)
                    {
                        dist[i]=dist[v]+1;
                        toVisit.push(i);
                    }
                }
            }
            for(int i=0;i<V;i++)
            {
                if(dist[i]==2)
                {
                    c++;
                }
            }
            cout<<c<<endl;
        }
        if(input=='s')
        {
            cin>>a>>b;
            a--;
            b--;
            c=0;
            queue<int> toVisit;
            int dist[V];
            int v;
            for(int i=0;i<V;i++)
            {
                dist[i]=INT_MAX;
            }
            toVisit.push(a);
            dist[a]=0;
            while(toVisit.empty()==false)
            {
                v=toVisit.front();
                toVisit.pop();
                for(int i=0;i<V;i++)
                {
                    if(gr[v][i]==1&&dist[i]>dist[v]+1)
                    {
                        dist[i]=dist[v]+1;
                        toVisit.push(i);
                    }
                }
            }
            if(dist[b]==INT_MAX)
                cout<<"Not connected"<<endl;
            else
                cout<<dist[b]<<endl;
        }
        cin>>input;
    }
    return 0;
}
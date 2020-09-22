#include <iostream>

using namespace std;
int E,V=101;
int dist[101]={0};
void dfsR(int v,int gr[][2])
{
    for(int i=0;i<V;i++)
    {
        bool con=false;
        for(int j=0;j<E;j++)
        {
            if(gr[j][0]==v&&gr[j][1]==i)
                con=true;
            if(gr[j][0]==i&&gr[j][1]==v)
                con=true;
        }
        if(con==true&&(dist[i]==-1||dist[i]>dist[v]))
        {
            dist[i]=dist[v]+1;
            dfsR(i,gr);
        }
    }
}
int dfs(int x,int gr[][2])
{
    for(int i=0;i<V;i++)
        dist[i]=-1;
    dist[x]=0;
    dfsR(x,gr);
    return 0;
}

int main()
{
    for(int k=0;k<5;k++)
    {
        cin>>E;
        int m=0;
        int gr[E][2];
        for(int i=0;i<E;i++)
        {
            cin>>gr[i][0]>>gr[i][1];
        }
        dfs(1,gr);
        for(int i=0;i<E;i++)
        {
            if(dist[gr[i][0]]==dist[gr[i][1]])
                m++;
        }
        cout<<m<<endl;
        for(int i=0;i<101;i++)
            dist[i]=0;
    }
    return 0;
}
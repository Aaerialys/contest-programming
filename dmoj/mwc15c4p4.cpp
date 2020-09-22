#include <iostream>

using namespace std;

int gr[1001][1001]={0};
void dfsR(int v,int distance[],int V)
{
    for(int i=0;i<V;i++)
    {
        if(gr[v][i]==1&&(distance[i]==-1||distance[i]>distance[v]+1))
        {
            distance[i]=distance[v]+1;
            dfsR(i,distance,V);
        }
    }
}
int dfs(int x,int y,int V)
{
    int distance[V];
    for(int i=0;i<V;i++)
        distance[i]=-1;
    distance[x]=0;
    dfsR(x,distance,V);
    return distance[y];
}
int main()
{
    int E,a,b;
    cin>>E;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b;
        gr[a][b]=1;
    }
    cin>>a>>b;
    if(dfs(a,b,1001)==-1)
        cout<<"Not Tangled";
    else
        cout<<"Tangled";
    return 0;
}
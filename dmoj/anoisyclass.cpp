#include <iostream>
#include <queue>

using namespace std;
int topS(int E,int V,int gr[][2])
{
    int in[V]={0},c=0,v;
    queue <int> toV;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<E;j++)
        {
            if(gr[j][1]==i)
            {
                in[i]++;
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        if(in[i]==0)
        {
            toV.push(i);
        }
    }
    while(toV.empty()==false)
    {
        v=toV.front();
        toV.pop();
        c++;
        for(int i=0;i<E;i++)
        {
            if(gr[i][0]==v)
            {
                in[gr[i][1]]--;
                if(in[gr[i][1]]==0)
                {
                    toV.push(gr[i][1]);
                }
            }
        }
    }
    if(c!=V)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int E,V;
    cin>>V>>E;
    V++;
    int graph[E][2];
    for(int i=0;i<E;i++)
    {
        cin>>graph[i][0]>>graph[i][1];
    }
    if(topS(E,V,graph)==0)
        cout<<"Y";
    else
        cout<<"N";
    return 0;
}
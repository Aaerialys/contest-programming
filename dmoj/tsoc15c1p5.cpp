#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int V,E,x,y,v,tim[200],dist[200];
queue<int> toV;
vector<int> gr[200];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,200)
        tim[i]=dist[i]=INT_MAX;
    cin>>V>>E;
    fori(0,E)
    {
        cin>>x>>y;
        gr[x].push_back(y); gr[y].push_back(x);
    }
    cin>>E;
    fori(0,E)
    {
        cin>>x;
        dist[x]=0;
        toV.push(x);
    }
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i]]>dist[v]+1)
            {
                dist[gr[v][i]]=dist[v]+1;
                toV.push(gr[v][i]);
            }
        }
    }
    tim[1]=0;
    toV.push(1);
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(min(tim[gr[v][i]],dist[gr[v][i]]*4)>tim[v]+1)
            {
                tim[gr[v][i]]=tim[v]+1;
                toV.push(gr[v][i]);
            }
        }
    }
    if(tim[V]==INT_MAX)
        cout<<"sacrifice bobhob314";
    else
        cout<<tim[V];
    return 0;
}
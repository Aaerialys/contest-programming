#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,x,y,a,b;
    cin>>V>>E>>x>>y;
    x--;
    y--;
    vector<int> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    queue<int> toVisit;
    int dist[V];
    int v;
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }
    toVisit.push(x);
    dist[x]=0;
    while(toVisit.empty()==false)
    {
        v=toVisit.front();
        toVisit.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i]]>dist[v]+1)
            {
                dist[gr[v][i]]=dist[v]+1;
                toVisit.push(gr[v][i]);
            }
        }
    }
    if(dist[y]==INT_MAX)
        cout<<"NO SHAHIR!";
    else
        cout<<"GO SHAHIR!";
    return 0;
}
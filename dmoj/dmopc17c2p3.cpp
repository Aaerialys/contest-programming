#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,R,x,y;
    cin>>V>>R;
    int bun[R];
    vector<int> gr[V];
    for(int i=0;i<V-1;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    for(int i=0;i<R;i++)
    {
        cin>>bun[i];
        bun[i]--;
    }
    cin>>x>>y;
    x--;
    y--;
    queue<int> toVisit;
    int bDist[V];
    int dist[V];
    int v;
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        bDist[i]=INT_MAX;
    }
    for(int i=0;i<R;i++)
    {
        toVisit.push(bun[i]);
        bDist[bun[i]]=0;
    }
    while(toVisit.empty()==false)
    {
        v=toVisit.front();
        toVisit.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(bDist[gr[v][i]]>bDist[v]+1)
            {
                bDist[gr[v][i]]=bDist[v]+1;
                toVisit.push(gr[v][i]);
            }
        }
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
                if(bDist[v]<bDist[gr[v][i]])
                {
                    bDist[gr[v][i]]=bDist[v];
                }
            }
        }
    }
    cout<<bDist[y];
    return 0;
}
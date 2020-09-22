#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,x,a,b,c,t,f;
    x=0;
    typedef pair<int,int> pii;
    cin>>t>>V>>E>>f;
    V++;
    int food[f];
    for(int i=0;i<f;i++)
    {
        cin>>food[i];
    }
    vector<pii> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        gr[a].push_back(make_pair(c,b));
    }
    priority_queue<pii,vector<pii>,greater<pii> > toVisit;
    int v;
    int dist[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[x]=0;
    toVisit.push(make_pair(0,x));
    while(toVisit.empty()==false)
    {
        v=toVisit.top().second;
        toVisit.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i].second]>dist[v]+gr[v][i].first)
            {
                dist[gr[v][i].second]=dist[v]+gr[v][i].first;
                toVisit.push(make_pair(dist[gr[v][i].second],gr[v][i].second));
            }
        }
    }
    x=0;
    for(int i=0;i<f;i++)
    {
        if(dist[food[i]]<t)
            x++;
    }
    cout<<x;
    return 0;
}
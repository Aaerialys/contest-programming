#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,x,a,b,c,q;
    cin>>V>>E>>x>>q;
    x--;
    vector<pii> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        gr[a].push_back(make_pair(c,b));
        gr[b].push_back(make_pair(c,a));
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
    for(int i=0;i<q;i++)
    {
        cin>>b;
        b--;
        if(dist[b]==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<dist[b]<<endl;
    }
    return 0;
}
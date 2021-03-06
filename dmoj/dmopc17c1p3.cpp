#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,int> edge;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,a,b,c;
    cin>>V>>E;
    vector<edge> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
    }
    priority_queue<pii,vector<pii>,greater<pii> > toVisit;
    int v;
    int dist[V],dist2[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        dist2[i]=INT_MAX;
    }
    dist[0]=0;
    dist2[0]=0;
    toVisit.push(make_pair(0,0));
    while(toVisit.empty()==false)
    {
        v=toVisit.top().second;
        toVisit.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i].first]>dist[v]+gr[v][i].second)
            {
                dist[gr[v][i].first]=dist[v]+gr[v][i].second;
                toVisit.push(make_pair(dist[gr[v][i].first],gr[v][i].first));
                dist2[gr[v][i].first]=dist2[v]+1;
            }
            if(dist[gr[v][i].first]==dist[v]+gr[v][i].second&&dist2[gr[v][i].first]>dist2[v]+1)
            {
                toVisit.push(make_pair(dist[gr[v][i].first],gr[v][i].first));
                dist2[gr[v][i].first]=dist2[v]+1;
            }
        }
    }
    if(dist[V-1]==INT_MAX)
        cout<<-1;
    else
        cout<<dist[V-1]<<" "<<dist2[V-1];
    return 0;
}
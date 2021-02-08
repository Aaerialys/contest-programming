#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,d,a,b,c,m=INT_MAX;
    typedef pair<int,int> pii;
    cin>>V>>E>>d;
    int dest[d];
    vector<pii> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        gr[a].push_back(make_pair(c,b));
        gr[b].push_back(make_pair(c,a));
    }
    for(int i=0;i<d;i++)
    {
        cin>>dest[i];
        dest[i]--;
    }
    priority_queue<pii> toVisit;
    int v;
    int dist[V];
    int prev[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=0;
        prev[i]=INT_MAX;
    }
    dist[0]=INT_MAX;
    toVisit.push(make_pair(INT_MAX,0));
    while(toVisit.empty()==false)
    {
        v=toVisit.top().second;
        toVisit.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i].second]<gr[v][i].first&&gr[v][i].first<dist[v]&&gr[v][i].second!=prev[v])
            {
                dist[gr[v][i].second]=gr[v][i].first;
                prev[gr[v][i].second]=v;
                toVisit.push(make_pair(dist[gr[v][i].second],gr[v][i].second));
            }
            if(dist[gr[v][i].second]<dist[v]&&gr[v][i].first>=dist[v]&&gr[v][i].second!=prev[v])
            {
                dist[gr[v][i].second]=dist[v];
                prev[gr[v][i].second]=v;
                toVisit.push(make_pair(dist[gr[v][i].second],gr[v][i].second));
            }
        }
    }
    for(int i=0;i<d;i++)
    {
        if(dist[dest[i]]<m)
        {
            m=dist[dest[i]];
        }
    }
    cout<<m;
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,x=0,a,b,c;
    typedef pair<int,int> pii;
    cin>>V>>E;
    vector<pii> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        gr[a].push_back(make_pair(c,b));
    }
    priority_queue<pii,vector<pii>,greater<pii> > toV;
    int v;
    int dist[V];
    int dist0[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX/3;
        dist0[i]=INT_MAX/3+1;
    }
    dist[x]=0;
    toV.push(make_pair(0,x));
    while(!toV.empty())
    {
        v=toV.top().second;
        toV.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            b=gr[v][i].first;
            a=gr[v][i].second;
            if(dist[a]>dist[v]+b)
            {
                dist0[a]=dist[a];
                if(dist0[v]+b>dist[v]+b)
                    dist0[a]=min(dist0[a],dist0[v]+b);
                dist[a]=dist[v]+b;
                toV.push(make_pair(dist[a],a));
            }
            else if(dist0[a]>dist[v]+b&&dist[v]+b>dist[a])
            {
                dist0[a]=dist[v]+b;
                toV.push(make_pair(dist0[a],a));
            }
            else if(dist0[a]>dist0[v]+b&&dist0[v]+b>dist[a])
            {
                dist0[a]=dist0[v]+b;
                toV.push(make_pair(dist0[v]+b,a));
            }

        }
    }
    if(dist0[V-1]>500000000)
        cout<<-1;
    else
        cout<<dist0[V-1];
    return 0;
}
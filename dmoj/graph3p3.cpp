#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int D=1000000;
    int V,E,a,b,c,d;
    typedef pair<int,int> pii;
    cin>>V>>E;
    vector<pii> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c>>d;
        a--;
        b--;
        gr[a].push_back(make_pair(c+d*D,b));
        gr[b].push_back(make_pair(c+d*D,a));
    }
    priority_queue<pii,vector<pii>,greater<pii> > toVisit;
    int v;
    int dist[V];
    int prev[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        prev[i]=INT_MAX;
    }
    dist[0]=0;
    toVisit.push(make_pair(0,0));
    while(toVisit.empty()==false)
    {
        v=toVisit.top().second;
        toVisit.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i].second]>gr[v][i].first&&gr[v][i].second!=prev[v])
            {
                dist[gr[v][i].second]=gr[v][i].first;
                prev[gr[v][i].second]=v;
                toVisit.push(make_pair(dist[gr[v][i].second],gr[v][i].second));
            }
        }
    }
    a=0;
    b=0;
    for(int i=0;i<V;i++)
    {
        if(dist[i]>=D)
        {
            a++;
            b+=dist[i]-D;
        }
        else
        {
            b+=dist[i];
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int p,V,E,a,b,c,x,m=INT_MAX;
    cin>>V>>E;
    V++;
    int gr[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            gr[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        gr[a][b]=c;
        gr[b][a]=c;
    }
    cin>>p;
    int pen[p][2];
    for(int i=0;i<p;i++)
    {
        cin>>pen[i][0]>>pen[i][1];
    }
    cin>>x;
    priority_queue<pii,vector<pii>,greater<pii> > toVisit;
    int distance[V];
    int v;
    for(int i=0;i<V;i++)
    {
        distance[i]=INT_MAX;
    }
    distance[x]=0;
    toVisit.push(make_pair(0,x));
    while(toVisit.empty()==false)
    {
        v=toVisit.top().second;
        toVisit.pop();
        for(int i=0;i<V;i++)
        {
            if(gr[v][i]!=INT_MAX&&distance[i]>distance[v]+gr[v][i])
            {
                distance[i]=distance[v]+gr[v][i];
                toVisit.push(make_pair(distance[i],i));
            }
        }
    }
    for(int i=0;i<p;i++)
    {
        if(distance[pen[i][0]]+pen[i][1]<m)
            m=distance[pen[i][0]]+pen[i][1];
    }
    cout<<m;
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,a,b,c,x,y,v;queue<int> toV;
    cin>>V>>E;
    vector<pair<int,int>> gr[V];int dist[V],dist2[V];bool inQ[V]={false};
    fori(0,E)
    {
        cin>>a>>b>>c;
        a--;b--;
        gr[a].push_back({b,c});gr[b].push_back({a,c});
    }
    x=0,y=V-1;
    fori(0,V)
        dist[i]=dist2[i]=INT_MAX/4;
    dist[x]=0;
    toV.push(x);
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        inQ[v]=false;
        fori(0,gr[v].size())
        {
            if(dist[gr[v][i].first]>dist[v]+gr[v][i].second)
            {
                dist2[gr[v][i].first]=min(dist2[v]+gr[v][i].second,dist[gr[v][i].first]);
                dist[gr[v][i].first]=dist[v]+gr[v][i].second;
                toV.push(gr[v][i].first);
                inQ[gr[v][i].first]=true;
            }
            if(dist[gr[v][i].first]<dist[v]+gr[v][i].second&&dist2[gr[v][i].first]>dist[v]+gr[v][i].second)
            {
                dist2[gr[v][i].first]=dist[v]+gr[v][i].second;
                toV.push(gr[v][i].first);
                inQ[gr[v][i].first]=true;
            }
            else if(dist2[gr[v][i].first]>dist2[v]+gr[v][i].second)
            {
                dist2[gr[v][i].first]=dist2[v]+gr[v][i].second;
                toV.push(gr[v][i].first);
                inQ[gr[v][i].first]=true;

            }
        }
    }
    cout<<dist2[y]<<endl;
    return 0;
}
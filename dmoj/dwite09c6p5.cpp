#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int ii=0;ii<5;ii++)
    {
        int V,E,c,xx=0,x;
        string a,b;
        typedef pair<int,int> pii;
        cin>>E;
        V=E+1;
        unordered_map<string,int> ports;
        vector<pii> gr[V];
        for(int i=0;i<E;i++)
        {
            cin>>a>>b>>c;
            if(ports.find(a)==ports.end())
            {
                ports.emplace(a,xx);
                xx++;
            }
            if(ports.find(b)==ports.end())
            {
                ports.emplace(b,xx);
                xx++;
            }
            gr[ports[a]].push_back(make_pair(c,ports[b]));
        }
        x=ports["YYZ"];
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
        cout<<dist[ports["SEA"]]<<endl;
    }
    return 0;
}
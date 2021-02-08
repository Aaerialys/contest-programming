#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int V,E,x,y,a,b,c,d,v,u,q,disto[100010],disfr[100010],sum[100010];
vector<pair<int,int>> grto[100010],grfr[100010],edge;
vector<int> shut[100010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > toV;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E>>x>>y; x--; y--;
    fori(0,E)
    {
        cin>>a>>b>>c>>d; a--; b--;
        shut[a].push_back(d);
        grto[a].push_back(make_pair(c,b));
        grfr[b].push_back(make_pair(c,a));
    }
    fori(0,V)
        disto[i]=disfr[i]=INT_MAX/3;
    disto[x]=0; disfr[y]=0;
    toV.push(make_pair(0,x));
    while(!toV.empty())
    {
        u=toV.top().first; v=toV.top().second; toV.pop();
        if(u>disto[v]) continue;
        fori(0,grto[v].size())
        {
            if(disto[grto[v][i].second]>disto[v]+grto[v][i].first)
            {
                disto[grto[v][i].second]=disto[v]+grto[v][i].first;
                toV.push(make_pair(disto[grto[v][i].second],grto[v][i].second));
            }
        }
    }
    toV.push(make_pair(0,y));
    while(!toV.empty())
    {
        u=toV.top().first; v=toV.top().second; toV.pop();
        if(u>disfr[v]) continue;
        fori(0,grfr[v].size())
        {
            if(disfr[grfr[v][i].second]>disfr[v]+grfr[v][i].first)
            {
                disfr[grfr[v][i].second]=disfr[v]+grfr[v][i].first;
                toV.push(make_pair(disfr[grfr[v][i].second],grfr[v][i].second));
            }
        }
    }
    fori(0,V)
    {
        forj(0,grto[i].size())
        {
            edge.push_back({disto[i]+disfr[grto[i][j].second]+grto[i][j].first,shut[i][j]});
        }
    }
    sort(edge.begin(),edge.end());
    sum[0]=0;
    fori(0,edge.size())
        sum[i+1]=sum[i]+edge[i].second;
    cin>>q;
    fori(0,q)
    {
        cin>>d;
        x=lower_bound(edge.begin(),edge.end(),make_pair(d,INT_MAX))-edge.begin();
        cout<<sum[x]<<"\n";
    }
    return 0;
}
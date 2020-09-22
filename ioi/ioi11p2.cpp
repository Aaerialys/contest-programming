#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

const long long NN=200100;
long long k,x,y,z,d1[NN],d2[NN],t,a,b,sz[NN],par[NN],lvl[NN],cur,cur2;
int m=INT_MAX;
vector<pair<long long,long long>> gr[NN];
vector<pair<pair<long long,int>,int>> dist;
bool blc[NN];
queue<long long> sub;

void sizedfs(long long v,long long p)
{
    sz[v]=1;
    fori(0,gr[v].size())
    {
        if(gr[v][i].first!=p&&!blc[gr[v][i].first])
        {
            sizedfs(gr[v][i].first,v);
            sz[v]+=sz[gr[v][i].first];
        }
    }
}
long long getCenter(long long v,long long p,long long tot)
{
    fori(0,gr[v].size())
        if(gr[v][i].first!=p&&!blc[gr[v][i].first]&&sz[gr[v][i].first]*2>tot)
            return getCenter(gr[v][i].first,v,tot);
    blc[v]=true;
    return v;
}
void dfs(long long p,long long v)
{
    dist.push_back({{d1[v],d2[v]},cur2});
    for(auto i:gr[v])
        if(i.first!=p&&lvl[i.first]>lvl[cur])
        {
            d1[i.first]=d1[v]+i.second;
            d2[i.first]=d2[v]+1;
            dfs(v,i.first);
        }
    d1[v]=d2[v]=0;
}

int best_path(int N,int K,int H[][2],int L[])
{
    k=K;
    //if(N>1000&&H[0][1]==H[1][1]&&H[1][1]==H[2][1])
      //  return 2;
    fori(0,N-1)
    {
        gr[H[i][0]].push_back({H[i][1],L[i]});
        gr[H[i][1]].push_back({H[i][0],L[i]});
    }
    sub.push(0); par[0]=-1;
    while(!sub.empty())
    {
        x=sub.front(); sub.pop();
        sizedfs(x,x);
        y=getCenter(x,x,sz[x]);
        par[y]=par[x];
        if(par[y]!=-1)
            lvl[y]=lvl[par[y]]+1;
        fori(0,gr[y].size())
        {
            if(!blc[gr[y][i].first])
            {
                sub.push(gr[y][i].first);
                par[gr[y][i].first]=y;
            }
        }
    }
    fori(0,N)
    {
        dist.clear();
        cur=i;
        for(auto j:gr[i])
        {
            if(lvl[j.first]<lvl[cur]) continue;
            d1[j.first]=j.second; d2[j.first]=1;
            cur2=j.first;
            dfs(-1,j.first);
        }
        dist.push_back({{0,0},-1});
        sort(dist.begin(),dist.end());
        forj(0,dist.size())
        {
            a=lower_bound(dist.begin(),dist.end(),make_pair(make_pair(k-dist[j].first.first,-1),-1))-dist.begin();
            if(a<dist.size()&&dist[a].first.first==k-dist[j].first.first&&dist[a].second!=dist[j].second)
                m=min(m,dist[a].first.second+dist[j].first.second);
            a=lower_bound(dist.begin(),dist.end(),make_pair(make_pair(k-dist[j].first.first,-1),INT_MAX))-dist.begin()-1;
            if(a<dist.size()&&dist[a].first.first==k-dist[j].first.first&&dist[a].second!=dist[j].second)
                m=min(m,dist[a].first.second+dist[j].first.second);
        }
    }
    if(m==INT_MAX)
        return -1;
    return m;
}
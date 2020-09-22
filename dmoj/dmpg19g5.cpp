#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

const long long N=200100;
long long n,k,x,y,z,d1[N],d2[N],t,a,b,sz[N],par[N],lvl[N],way[N],add[N],cur,cur2;
vector<pair<long long,long long>> gr[N];
vector<pair<pair<long long,long long>,long long>> dist;
bool blc[N];
queue<long long> sub;

long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
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
    dist.push_back({{d1[v],cur2},v});
    for(auto i:gr[v])
        if(i.first!=p&&lvl[i.first]>lvl[cur])
        {
            d1[i.first]=d1[v]+i.second;
            d2[i.first]=d2[v]+1;
            dfs(v,i.first);
        }
    d1[v]=d2[v]=0;
}
void dfs2(long long p,long long v)
{
    for(auto i:gr[v])
        if(i.first!=p&&lvl[i.first]>lvl[cur])
        {
            dfs2(v,i.first);
            add[v]+=add[i.first];
            add[i.first]=0;
        }
    if(v==cur)
        add[v]/=2;
    way[v]+=add[v];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    fori(0,n-1)
    {
        cin>>x>>y>>z; x--; y--;
        gr[x].push_back({y,z});
        gr[y].push_back({x,z});
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
    fori(0,n)
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
        dist.push_back({{0,-1},i});
        sort(dist.begin(),dist.end());
        forj(0,dist.size())
        {
            a=lower_bound(dist.begin(),dist.end(),make_pair(make_pair(k-dist[j].first.first,LLONG_MAX),LLONG_MAX))-lower_bound(dist.begin(),dist.end(),make_pair(make_pair(k-dist[j].first.first,-1LL),LLONG_MIN));
            b=upper_bound(dist.begin(),dist.end(),make_pair(make_pair(k-dist[j].first.first,dist[j].first.second),LLONG_MAX))-lower_bound(dist.begin(),dist.end(),make_pair(make_pair(k-dist[j].first.first,dist[j].first.second),LLONG_MIN));
            t+=a-b;
            cur2=dist[j].second;
            add[dist[j].second]+=a-b;
        }
        dfs2(-1,i); add[i]=0;
    }
    t/=2;
    fori(0,n)
    {
        a=gcd(t,way[i]);
        if(a!=0)
            cout<<way[i]/a<<" / "<<t/a<<"\n";
        else
            cout<<"0 / 1\n";
    }
    return 0;
}
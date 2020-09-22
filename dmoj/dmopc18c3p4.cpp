#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const long long N=201000;
long long k,n,x,y,z,sz[N],numb[N],dist[N];
vector<pair<long long,long long>> gr[N];

void sizedfs(long long v,long long p)
{
    sz[v]=numb[v];
    fori(0,gr[v].size())
        if(gr[v][i].first!=p)
        {
            sizedfs(gr[v][i].first,v);
            sz[v]+=sz[gr[v][i].first];
        }
}
long long getCenter(long long v,long long p)
{
    fori(0,gr[v].size())
        if(gr[v][i].first!=p&&sz[gr[v][i].first]*2>k)
            return getCenter(gr[v][i].first,v);
    return v;
}
void dfs(long long v,long long p)
{
    fori(0,gr[v].size())
        if(gr[v][i].first!=p)
        {
            dist[gr[v][i].first]=dist[v]+gr[v][i].second;
            dfs(gr[v][i].first,v);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>k>>n;
    fori(0,k)
    {
        cin>>x; x--;
        numb[x]++;
    }
    fori(0,n-1)
    {
        cin>>x>>y>>z; x--; y--;
        gr[x].push_back({y,z}); gr[y].push_back({x,z});
    }
    sizedfs(0,-1);
    x=getCenter(0,-1);
    dfs(x,-1);
    x=0;
    fori(0,n)
        x+=numb[i]*dist[i];
    cout<<x;
    return 0;
}
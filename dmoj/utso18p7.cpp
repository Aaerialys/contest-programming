#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

const long long N=100100,M=1e9+7;
long long n,x,y,z,a,b,c,q,sz[N],par[N],post[N],pop[N],lvl[N],dist[N][17],rem[N],news[N];
vector<long long> gr[N];
bool blc[N];
queue<long long> sub;

long long fpow(long long a,long long b)
{
    if(b==0)
        return 1;
    long long t=fpow(a,b/2);
    if(b&1)
        return t*t%M*a%M;
    return t*t%M;
}

void sizedfs(long long v,long long p)
{
    sz[v]=1;
    fori(0,gr[v].size())
    {
        if(gr[v][i]!=p&&!blc[gr[v][i]])
        {
            sizedfs(gr[v][i],v);
            sz[v]+=sz[gr[v][i]];
        }
    }
}

long long getCenter(long long v,long long p,long long tot)
{
    fori(0,gr[v].size())
        if(gr[v][i]!=p&&!blc[gr[v][i]]&&sz[gr[v][i]]*2>tot)
            return getCenter(gr[v][i],v,tot);
    blc[v]=true;
    return v;
}
void dfs(long long v,long long p,long long l)
{
    fori(0,gr[v].size())
        if(gr[v][i]!=p&&lvl[gr[v][i]]>l)
        {
            dist[gr[v][i]][l]=(dist[v][l]*pop[v])%M;
            dfs(gr[v][i],v,l);
        }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    fori(0,n)
        cin>>pop[i];
    fori(0,n-1)
    {
        cin>>x>>y; x--; y--;
        gr[x].push_back(y); gr[y].push_back(x);
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
            if(!blc[gr[y][i]])
            {
                sub.push(gr[y][i]);
                par[gr[y][i]]=y;
            }
        }
    }
    fori(0,n)
    {
        dist[i][lvl[i]]=1;
        dfs(i,-1,lvl[i]);
    }
    fori(0,q)
    {
        cin>>x;
        if(x==1)
        {
            cin>>y>>z; y--; a=y;
            while(a!=-1)
            {
                news[a]+=z*pop[y]%M*dist[y][lvl[a]]%M; news[a]%=M;
                if(lvl[a]>0)
                    rem[a]=(rem[a]+z*pop[y]%M*dist[y][lvl[a]-1]%M)%M;
                a=par[a];
            }
        }
        if(x==2)
        {
            cin>>y; y--; a=y; z=(news[y]*fpow(pop[y],M-2))%M;
            while(a!=-1)
            {
                if(lvl[a]>0)
                    z=(z+(news[par[a]]-rem[a])*dist[y][lvl[par[a]]]%M*fpow(pop[par[a]],M-2))%M;
                a=par[a];
            }
            cout<<(z+M*10)%M<<endl;
        }
    }
    return 0;
}
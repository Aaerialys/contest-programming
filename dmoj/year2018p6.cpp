#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

const long long N=50100,B=260,MAX=LLONG_MAX>>2;
long long n,q,a,b,l,r,dist[N],val[N],first[N],ans[N],par[N],vis[N],st[18][N*4];
vector<long long> etour,gr[N];
multiset<long long> num,dif;

struct query
{
    long long l,r,i;
};
bool cmp(query x,query y)
{
    if(first[x.l]/B==first[y.l]/B)
        return first[x.r]<first[y.r];
    return first[x.l]<first[y.l];
}
query que[N];

void dfs(long long p,long long v)
{
    etour.push_back(v);
    for(auto i:gr[v])
        if(i!=p)
        {
            dist[i]=dist[v]+1;
            par[i]=v;
            dfs(v,i);
            etour.push_back(v);
        }
}
void xoradd(long long v)
{
    if(vis[v])
    {
        dif.erase(dif.find(val[v]-*next(num.find(val[v]),-1)));
        dif.erase(dif.find(*next(num.find(val[v]),1)-val[v]));
        dif.insert(*next(num.find(val[v]),1)-*next(num.find(val[v]),-1));
        num.erase(num.find(val[v]));
        vis[v]=false;
        return;
    }
    num.insert(val[v]);
    //long long aaa=val[v]-*next(num.find(val[v]),-1);
    dif.insert(val[v]-*next(num.find(val[v]),-1));
    //aaa=*next(num.find(val[v]),1)-val[v];
    dif.insert(*next(num.find(val[v]),1)-val[v]);
    //aaa=*next(num.find(val[v]),1)-*next(num.find(val[v]),-1);
    dif.erase(dif.find(*next(num.find(val[v]),1)-*next(num.find(val[v]),-1)));
    vis[v]=true;
}
long long lca(long long x,long long y)
{
    long long a=first[x],b=first[y],l;
    if(a>b)
        swap(a,b);
    l=floor(log2(b-a+1));
    if(dist[st[l][a]]<dist[st[l][b-(1<<l)+1]])
        return st[l][a];
    return st[l][b-(1<<l)+1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fori(0,n)
        cin>>val[i];
    fori(1,n)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b); gr[b].push_back(a);
    }
    dfs(-1,0);
    fori(0,etour.size())
        st[0][i]=etour[i];
    int xxx=etour.size();
    fori(1,17)
        forj(0,xxx-(1<<i))
        {
            if(dist[st[i-1][j]]<dist[st[i-1][j+(1<<(i-1))]])
                st[i][j]=st[i-1][j];
            else
                st[i][j]=st[i-1][j+(1<<(i-1))];
        }
    fori(0,etour.size())
        if(first[etour[i]]==0)
            first[etour[i]]=i;
    first[0]=0;
    fori(0,q)
    {
        cin>>que[i].l>>que[i].r; que[i].l--; que[i].r--; que[i].i=i;
        if(first[que[i].l]>first[que[i].r])
            swap(que[i].l,que[i].r);
    }
    sort(que,que+q,cmp);
    num.insert(MAX); num.insert(-MAX);
    dif.insert(MAX+MAX);
    l=r=0;
    fori(0,q)
    {
        a=que[i].l; b=que[i].r;
        if(dist[a]<dist[l])
            swap(a,l);
        while(dist[a]>dist[l])
        {
            xoradd(a);
            a=par[a];
        }
        while(a!=l)
        {
            xoradd(a); xoradd(l);
            a=par[a]; l=par[l];
        }
        if(dist[b]<dist[r])
            swap(b,r);
        while(dist[b]>dist[r])
        {
            xoradd(b);
            b=par[b];
        }
        while(b!=r)
        {
            xoradd(b); xoradd(r);
            b=par[b]; r=par[r];
        }
        xoradd(lca(que[i].l,que[i].r));
        ans[que[i].i]=*dif.begin();
        xoradd(lca(que[i].l,que[i].r));
        l=que[i].l; r=que[i].r;
    }
    fori(0,q)
        cout<<ans[i]<<"\n";
    return 0;
}
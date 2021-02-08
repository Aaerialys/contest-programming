#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

struct edge
{
    int a,b,c;
};

int V,E,x,y,z,t=0;
const int VV=50010,LVL=16;

bool cmp(edge x,edge y)
{
    return x.c<y.c;
}
class djSet
{
private:
    int V;
    vector<int> parent;
public:
    djSet(int v)
    {
        V=v;
        parent.reserve(V);
        for(int i=0;i<V;i++)
            parent[i]=i;
    }
    int lead(int x)
    {
        if(parent[x]!=x)
            parent[x]=lead(parent[x]);
        return parent[x];
    }
    void link(int x,int y)
    {
        x=lead(x);
        y=lead(y);
        parent[x]=y;
    }
};

vector<pair<int,int>> mst[VV];
int dist[VV],dep[VV],par[VV][LVL],m[VV][LVL],m2[VV][LVL];
bool ee[100001];

void dfs(int v)
{
    int x,y;
    fori(0,mst[v].size())
    {
        x=mst[v][i].first; y=mst[v][i].second;
        if(dep[x]>dep[v]+1)
        {
            dep[x]=dep[v]+1;
            dist[x]=dist[v]+y;
            dfs(x);
        }
    }
}

int lca(int a,int b)
{

    if(dep[a]>dep[b])
        swap(a,b);
    x=dep[b]-dep[a];
    fori(0,LVL)
        if(x&(1<<i))
            b=par[b][i];
    fori(0,LVL)
    {
        if(par[a][LVL-i-1]!=par[b][LVL-i-1])
        {
            a=par[a][LVL-i-1];
            b=par[b][LVL-i-1];
        }
    }
    if(a==b)
        return a;
    return par[a][0];
}

int medge(int x,int y,int xy)
{
    int z=lca(x,y),za=0,zb=0,zc=0,zd=0,b=dep[x]-dep[z];
    fori(1,LVL+1)
    {
        if(b>=1<<(LVL-i))
        {
            if(za>m[x][LVL-i])
                zc=max(zc,m[x][LVL-i]);
            za=max(za,m[x][LVL-i]);
            zc=max(zc,m2[x][LVL-i]);
            x=par[x][LVL-i];
            b=dep[x]-dep[z];
        }
    }
    b=dep[y]-dep[z];
    fori(1,LVL+1)
    {
        if(b>=1<<(LVL-i))
        {
            if(zb>m[y][LVL-i])
                zd=max(zd,m[y][LVL-i]);
            zb=max(zb,m[y][LVL-i]);
            zd=max(zd,m2[y][LVL-i]);
            y=par[y][LVL-i];
            b=dep[y]-dep[z];
        }
    }
    if(za==xy)
        za=zc;
    if(zb==xy)
        zb=zd;
    if(max(za,zb)==0)
        return INT_MIN/2;
    return max(za,zb);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E;
    vector<edge> gr;
    int t=0,cc=0;
    fori(0,E)
    {
        cin>>x>>y>>z;
        gr.push_back({x-1,y-1,z});
    }
    sort(gr.begin(),gr.end(),cmp);
    djSet djs(V);
    fori(0,E)
    {
        if(djs.lead(gr[i].a)!=djs.lead(gr[i].b))
        {
            mst[gr[i].a].push_back(make_pair(gr[i].b,gr[i].c)); mst[gr[i].b].push_back(make_pair(gr[i].a,gr[i].c));
            djs.link(gr[i].a,gr[i].b);
            t+=gr[i].c; cc++;
            ee[i]=true;
        }
    }
    if(cc<V-1||E<V)
    {
        cout<<-1;
        return 0;
    }
    fori(1,V)
        dep[i]=INT_MAX;
    dfs(0);
    par[0][0]=VV-1;
    fori(0,LVL)
        par[VV-1][i]=VV-1;
    fori(0,V)
    {
        forj(0,mst[i].size())
        {
            if(dep[mst[i][j].first]<dep[i])
            {
                par[i][0]=mst[i][j].first;
                m[i][0]=mst[i][j].second;
            }
            else
            {
                par[mst[i][j].first][0]=i;
                m[mst[i][j].first][0]=mst[i][j].second;
            }
        }
    }
    fori(1,LVL)
        forj(0,V)
            par[j][i]=par[par[j][i-1]][i-1];
    fori(1,16)
        forj(0,V)
        {
            m[j][i]=max(m[j][i-1],m[par[j][i-1]][i-1]);
            x=min(m[j][i-1],m[par[j][i-1]][i-1]);
            y=m2[j][i-1];
            z=m2[par[j][i-1]][i-1];
            if(x==m[j][i]) x=0;
            if(y==m[j][i]) y=0;
            if(z==m[j][i]) z=0;
            m2[j][i]=max(max(x,y),z);
        }
    int tt=INT_MAX;
    fori(0,E)
    {
        if(!ee[i])
        {
            tt=min(tt,t+gr[i].c-medge(gr[i].a,gr[i].b,gr[i].c));
        }
    }
    if(tt>INT_MAX/2)
        cout<<-1<<endl;
    else
        cout<<tt<<endl;
    return 0;
}
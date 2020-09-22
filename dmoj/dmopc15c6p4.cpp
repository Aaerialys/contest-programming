#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

struct edge
{
    int a,b,c;
};
bool cmp(edge x,edge y)
{
    return x.c<y.c;
}
class djSet
{
private:
    int V;
    vector<int> parent;
    vector<int> depth;
public:
    djSet(int v)
    {
        V=v;
        parent.reserve(V);
        depth.reserve(V);
    }
    void make_set(int x)
    {
        parent[x]=x;
        depth[x]=0;
    }
    int leader(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=leader(parent[x]);
        }
        return parent[x];
    }
    void link(int x,int y)
    {
        x=leader(x);
        y=leader(y);
        parent[x]=y;
    }
    int leadNPC(int x)
    {
        if(parent[x]!=x)
        {
            return leader(parent[x]);
        }
        return parent[x];
    }
    void linkNPC(int x,int y)
    {
        x=leadNPC(x);
        y=leadNPC(y);
        if(depth[x]>depth[y])
            parent[y]=x;
        else
        {
            parent[x]=y;
            if(depth[x]==depth[y])
                depth[y]++;
        }
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long V,k,a,t=0;
    vector<edge> gr;
    vector<edge> mst;
    cin>>V>>k;
    for(long long i=0;i<V-1;i++)
    {
        cin>>a;
        gr.push_back({i,i+1,a});
    }
    for(long long i=0;i<V-k;i++)
    {
        gr.push_back({i,i+k,0});
    }
    sort(gr.begin(),gr.end(),cmp);
    djSet djs(V);
    fori(0,V)
    {
        djs.make_set(i);
    }
    fori(0,gr.size())
    {
        if(djs.leader(gr[i].a)!=djs.leader(gr[i].b))
        {
            mst.push_back(gr[i]);
            djs.link(gr[i].a,gr[i].b);
            t+=gr[i].c;
        }
    }
    cout<<t;
    return 0;
}
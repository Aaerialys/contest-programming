#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

struct edge
{
    int a,b,c,d;
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
    long long n,m,p,q,x,y,z,t=0,total=0;
    cin>>n>>m>>p>>q;
    vector<edge> gr;
    fori(0,p)
    {
        cin>>x>>y>>z;
        x--;
        y--;
        total+=z*n;
        gr.push_back({x,y,z,0});
    }
    fori(0,q)
    {
        cin>>x>>y>>z;
        x--;
        y--;
        total+=z*m;
        gr.push_back({x,y,z,1});
    }
    sort(gr.begin(),gr.end(),cmp);
    djSet city(p);
    djSet planet(q);
    fori(0,m) city.make_set(i);
    fori(0,n) planet.make_set(i);
    long long cnumb=m,pnumb=n;
    cout<<endl;
    fori(0,p+q)
    {
        if(gr[i].d==0)
        {
            if(city.leader(gr[i].a)!=city.leader(gr[i].b))
            {
                city.link(gr[i].a,gr[i].b);
                t+=gr[i].c*pnumb;
                cnumb--;
            }
        }
        if(gr[i].d==1)
        {
            if(planet.leader(gr[i].a)!=planet.leader(gr[i].b))
            {
                planet.link(gr[i].a,gr[i].b);
                t+=gr[i].c*cnumb;
                pnumb--;
            }
        }
    }
    cout<<total-t<<endl;
    return 0;
}
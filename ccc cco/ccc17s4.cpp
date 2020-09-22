#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
struct edge
{
    long long a,b,c,n;
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
public:
    djSet(int v)
    {
        V=v;
        parent.reserve(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
    }
    int lead(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=lead(parent[x]);
        }
        return parent[x];
    }
    void link(int x,int y)
    {
        x=lead(x);
        y=lead(y);
        parent[x]=y;
    }
};

int main()
{
    long long V,E,d,x,y,z,t=0;
    cin>>V>>E>>d;
    d*=1000000;
    d+=500000; 
    vector<edge> gr;
    vector<edge> mst;
    fori(0,E)
    {
        cin>>x>>y>>z;
        x--;
        y--;
        z*=1000000;
        z+=i;
        if(i<V-1)
            gr.push_back({x,y,z,1});
        else
            gr.push_back({x,y,z,0});
    }
    sort(gr.begin(),gr.end(),cmp);
    djSet djs(V);
    fori(0,E)
    {
        if(djs.lead(gr[i].a)!=djs.lead(gr[i].b))
        {
            mst.push_back(gr[i]);
            djs.link(gr[i].a,gr[i].b);
            t+=gr[i].c;
        }
    }
    x=0;
    fori(0,V-1)
    {
        if(mst[i].n ==0)
            x++;
    }
    djSet newdjs(V);
    if(mst[V-2].c<d&&mst[V-2].n==0)
    {
        fori(0,V-1)
        {
            if(mst[i].c<mst[V-2].c-500000||mst[i].n==1)
            {
                newdjs.link(mst[i].a,mst[i].b);
            }
        }
        fori(0,E)
        {
            if(gr[i].n==1&&gr[i].c>mst[V-2].c+500000&&gr[i].c<=d&&newdjs.lead(gr[i].a)!=newdjs.lead(gr[i].b)){
                cout<<x-1<<endl;
                return 0;
            }
        }
    }
    cout<<x<<endl;
    return 0;
}
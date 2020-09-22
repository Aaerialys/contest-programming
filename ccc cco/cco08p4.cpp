#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

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
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,r,c,t=0;
    char x;
    cin>>r>>c;
    V=r*c;
    djSet city(V);
    for(int i=0;i<V;i++)
    {
        city.make_set(i);
    }
    for(int i=0;i<V;i++)
    {
        cin>>x;
        switch(x)
        {
        case 'E':
            city.link(i,i+1);
            break;
        case 'W':
            city.link(i,i-1);
            break;
        case 'N':
            city.link(i,i-c);
            break;
        case 'S':
            city.link(i,i+c);
            break;
        }
    }
    bool lead[V]={false};
    for(int i=0;i<V;i++)
    {
        if(lead[city.leader(i)]==false)
        {
            t++;
            lead[city.leader(i)]=true;
        }
    }
    cout<<t;
    return 0;
}
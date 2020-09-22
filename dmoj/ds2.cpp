#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;

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
    void makeSet(int x)
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
    int leadNPC(int x)
    {
        if(parent[x]!=x)
        {
            return leader(parent[x]);
        }
        return parent[x];
    }
    void link(int x,int y)
    {
        x=leader(x);
        y=leader(y);
        parent[x]=y;
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
    int V,E,a,b;
    cin>>V>>E;
    djSet gr(V);
    vector<int> tree;
    for(int i=0;i<V;i++)
        gr.makeSet(i);
    for(int i=0;i<E;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        if(gr.leader(a)!=gr.leader(b))
        {
            gr.link(a,b);
            tree.push_back(i);
        }
        if(tree.size()==V-1)
            break;
    }
    if(tree.size()==V-1)
    {
        for(int i=0;i<V-1;i++)
        {
            cout<<tree[i]+1<<endl;
        }
    }
    else
        cout<<"Disconnected Graph"<<endl;
    return 0;
}
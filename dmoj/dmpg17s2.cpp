#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

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
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,q,a,b;
    char ch;
    cin>>n>>q;
    djSet city(n);
    fori(0,q)
    {
        cin>>ch>>a>>b;
        a--;
        b--;
        if(ch=='A')
        {
            city.link(a,b);
        }
        if(ch=='Q')
        {
            if(city.lead(a)==city.lead(b))
                cout<<"Y\n";
            else
                cout<<"N\n";
        }
    }
    return 0;
}
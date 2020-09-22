#include <bits/stdc++.h>

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
    }
    void make_set(int x)
    {
        parent[x]=x;
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
    int n,m,a,b,c;
    cin>>n>>m;
    djSet school(n);
    for(int i=0;i<n;i++)
    {
        school.make_set(i);
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        b--;
        for(int j=1;j<a;j++)
        {
            cin>>c;
            c--;
            school.link(b,c);
        }
    }
    a=0;
    b=school.leader(0);
    for(int i=0;i<n;i++)
    {
        if(school.leader(i)==b)
        {
            a++;
        }

    }
    cout<<a<<endl;
    for(int i=0;i<n;i++)
    {
        if(school.leader(i)==b)
        {
            cout<<i+1<<" ";
        }

    }
    return 0;
}
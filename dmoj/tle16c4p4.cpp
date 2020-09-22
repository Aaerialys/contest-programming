#include <bits/stdc++.h>
#define fori(a,b) for(unsigned int i=a;i<b;i++)
#define forj(a,b) for(unsigned int j=a;j<b;j++)
#define fork(a,b) for(unsigned int k=a;k<b;k++)

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
    long long n,m,q,a,b,c,d;
    cin>>n>>m>>q;
    djSet djs(n);
    vector<pair<int,int>> gr[n];
    vector<int> tree;
    queue<int> toV;
    long long dist[n];
    long long dist0[n];
    long long dist1[n];
    long long max0[n];
    long long max1[n];
    fori(0,m)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
        djs.link(a,b);
    }
    fori(0,n)
    {
        dist[i]=dist0[i]=dist1[i]=LLONG_MAX;
        max1[i]=-1;
        if(djs.lead(i)==i)
        {
            toV.push(i);
            dist[i]=0;
            tree.push_back(i);
        }
    }
    while(!toV.empty())
    {
        a=toV.front();
        toV.pop();
        fori(0,gr[a].size())
        {
            b=gr[a][i].first;
            c=gr[a][i].second;
            if(dist[b]>dist[a]+c)
            {
                dist[b]=dist[a]+c;
                toV.push(b);
            }
        }
    }
    fori(0,n)
    {
        if(max1[djs.lead(i)]+1<dist[i]+1)
        {
            max1[djs.lead(i)]=dist[i];
            max0[djs.lead(i)]=i;
        }
    }
    fori(0,tree.size())
    {
        toV.push(max0[tree[i]]);
        dist0[max0[tree[i]]]=0;
    }
    while(!toV.empty())
    {
        a=toV.front();
        toV.pop();
        fori(0,gr[a].size())
        {
            b=gr[a][i].first;
            c=gr[a][i].second;
            if(dist0[b]>dist0[a]+c)
            {
                dist0[b]=dist0[a]+c;
                toV.push(b);
            }
        }
    }
    fori(0,n)
    {
        max1[i]=-1;
    }
    fori(0,n)
    {
        if(max1[djs.lead(i)]+1<dist0[i]+1)
        {
            max1[djs.lead(i)]=dist0[i];
            max0[djs.lead(i)]=i;
        }
    }
    fori(0,tree.size())
    {
        toV.push(max0[tree[i]]);
        dist1[max0[tree[i]]]=0;
    }
    while(!toV.empty())
    {
        a=toV.front();
        toV.pop();
        fori(0,gr[a].size())
        {
            b=gr[a][i].first;
            c=gr[a][i].second;
            if(dist1[b]>dist1[a]+c)
            {
                dist1[b]=dist1[a]+c;
                toV.push(b);
            }
        }
    }
    if(q==1)
    {
        fori(0,tree.size())
        {
            max1[tree[i]]=-1;
        }
        fori(0,n)
        {
            a=djs.lead(i);
            max1[a]=max(max1[a],dist0[i]);
        }
        d=0;
        fori(0,tree.size())
        {
            d+=max1[tree[i]];
        }
        d+=tree.size()-1;
        cout<<d;
    }
    if(q==2)
    {
        fori(0,n)
        {
            max1[i]=LLONG_MAX;
        }
        fori(0,n)
        {
            a=djs.lead(i);
            if(max(dist0[i],dist1[i])<max1[a])
            {
                max1[a]=max(dist0[i],dist1[i]);
            }
        }
        a=-1;
        b=-1;
        fori(0,tree.size())
        {
            d=tree[i];
            if(max1[d]>a)
            {
                b=a;
                a=max1[d];
            }
            else if(max1[d]>b)
            {
                b=max1[d];
            }
        }
        d=a;
        if(tree.size()>1&&b==a)
            d=a+1;
        cout<<d<<endl;
    }
    return 0;
}
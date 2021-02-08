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

int travelTime(int N, int M, int L, int A[], int B[], int T[])
{
    int n=N,m=M,l=L,a,b,c,d;
    vector<pair<int,int>> gr[n];
    vector<int> tree;
    int dist[n],dist0[n],dist1[n],max0[n],max1[n];
    djSet djs(n);
    fori(0,m)
    {
        a=A[i];
        b=B[i];
        c=T[i];
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
        djs.link(a,b);
    }
    queue<int> toV;
    fori(0,n)
    {
        dist[i]=dist0[i]=dist1[i]=INT_MAX;
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
    fori(0,n)
    {
        max1[i]=INT_MAX;
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
    c=-1;
    m=-1;
    fori(0,tree.size())
    {
        d=tree[i];
        if(max1[d]>a)
        {
            c=b;
            b=a;
            a=max1[d];
        }
        else if(max1[d]>b)
        {
            c=b;
            b=max1[d];
        }
        else if(max1[d]>c)
        {
            c=max1[d];
        }
    }
    fori(0,n)
    {
        
        m=max(m,dist0[i]);
    }
    d=m;
    if(tree.size()>1)
        d=max(d,a+b+l);
    if(tree.size()>2)
        d=max(d,b+c+l*2);
    return d;
}

int main()
{
    int n,m,l;
    cin>>n>>m>>l;
    int a[n],b[n],t[n];
    fori(0,m)
    {
        cin>>a[i];
    }
    fori(0,m)
    {
        cin>>b[i];
    }
    fori(0,m)
    {
        cin>>t[i];
    }
    cout<<travelTime(n,m,l,a,b,t);
    return 0;
}
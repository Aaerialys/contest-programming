#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,a,b,c,d,v;
    cin>>n;
    vector<long long> tree[n];
    vector<long long> trew[n];
    long long dist[n];
    long long dist0[n];
    long long dist1[n];
    dist0[0]=LLONG_MAX;
    dist1[0]=LLONG_MAX;
    fori(1,n)
    {
        dist[i]=LLONG_MAX;
        dist0[i]=LLONG_MAX;
        dist1[i]=LLONG_MAX;
        cin>>a>>b>>c;
        a--;
        b--;
        tree[a].push_back(b);
        trew[a].push_back(c);
        tree[b].push_back(a);
        trew[b].push_back(c);
    }
    queue<long long> toV;
    toV.push(0);
    dist[0]=0;
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        b=tree[v].size();
        fori(0,b)
        {
            if(dist[tree[v][i]]==LLONG_MAX)
            {
                dist[tree[v][i]]=dist[v]+trew[v][i];
                toV.push(tree[v][i]);
            }
        }
    }
    a=0;
    b=0;
    fori(0,n)
    {
        if(a<dist[i])
        {
            a=dist[i];
            b=i;
        }
    }
    dist0[b]=0;
    toV.push(b);
    c=b;
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        b=tree[v].size();
        fori(0,b)
        {
            if(dist0[tree[v][i]]==LLONG_MAX)
            {
                dist0[tree[v][i]]=dist0[v]+trew[v][i];
                toV.push(tree[v][i]);
            }
        }
    }
    a=0;
    b=0;
    fori(0,n)
    {
        if(a<dist0[i])
        {
            a=dist0[i];
            b=i;
        }
    }
    dist1[b]=0;
    toV.push(b);
    d=b;
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        b=tree[v].size();
        fori(0,b)
        {
            if(dist1[tree[v][i]]==LLONG_MAX)
            {
                dist1[tree[v][i]]=dist1[v]+trew[v][i];
                toV.push(tree[v][i]);
            }
        }
    }
    a=LLONG_MIN;
    b=LLONG_MIN;
    fori(0,n)
    {
        if(i!=d)
        {
            a=max(a,dist0[i]);
        }
        if(i!=c)
        {
            b=max(b,dist1[i]);
        }
    }
    cout<<max(a,b);
    return 0;
}
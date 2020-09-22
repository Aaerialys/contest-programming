#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,v;
    cin>>n;
    vector<int> gr[n];
    int dist[n];
    int dist0[n];
    int dist1[n];
    fori(0,n-1)
    {
        dist[i]=INT_MAX;
        dist0[i]=INT_MAX;
        dist1[i]=INT_MAX;
        cin>>a>>b;
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dist[n-1]=INT_MAX;
    dist0[n-1]=INT_MAX;
    dist1[n-1]=INT_MAX;
    dist[0]=0;
    queue<int> toV;
    toV.push(0);
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        b=gr[v].size();
        fori(0,b)
        {
            if(dist[gr[v][i]]==INT_MAX)
            {
                dist[gr[v][i]]=dist[v]+1;
                toV.push(gr[v][i]);
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
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        b=gr[v].size();
        fori(0,b)
        {
            if(dist0[gr[v][i]]==INT_MAX)
            {
                dist0[gr[v][i]]=dist0[v]+1;
                toV.push(gr[v][i]);
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
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        b=gr[v].size();
        fori(0,b)
        {
            if(dist1[gr[v][i]]==INT_MAX)
            {
                dist1[gr[v][i]]=dist1[v]+1;
                toV.push(gr[v][i]);
            }
        }
    }
    fori(0,n)
    {
        cout<<max(dist0[i],dist1[i])+1<<"\n";
    }
    return 0;
}
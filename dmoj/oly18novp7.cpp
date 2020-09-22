#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x,y,dist[100001];
    vector<int> gr[100001];
    queue<int> toVisit;
    cin>>x>>y;
    int v;
    for(int i=0;i<100001;i++)
    {
        dist[i]=INT_MAX;
        if(i>0)
            gr[i].push_back(i-1);
        if(i<100000)
            gr[i].push_back(i+1);
        if(i<=50000)
            gr[i].push_back(i*2);
    }
    toVisit.push(x);
    dist[x]=0;
    while(toVisit.empty()==false)
    {
        v=toVisit.front();
        toVisit.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i]]>dist[v]+1)
            {
                dist[gr[v][i]]=dist[v]+1;
                toVisit.push(gr[v][i]);
            }
        }
    }
    cout<<dist[y]<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t,a,b,c,x=0;
    cin>>n>>t;
    int dist[n],dist0[n],dist1[n];
    vector<pair<int,int>> gr[n];
    dist[0]=dist0[0]=dist1[0]=INT_MAX;
    fori(1,n)
    {
        dist[i]=dist0[i]=dist1[i]=INT_MAX;
        cin>>a>>b>>c;
        x+=c;
        a--;
        b--;
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
    }
    queue<int> toV;
    toV.push(0);
    dist[0]=0;
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
    a=-1;
    fori(0,n)
    {
        if(dist[i]+1>a+1)
        {
            a=dist[i];
            b=i;
        }
    }
    toV.push(b);
    dist0[b]=0;
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
    a=-1;
    fori(0,n)
    {
        if(dist0[i]+1>a+1)
        {
            a=dist0[i];
            b=i;
        }
    }
    toV.push(b);
    dist1[b]=0;
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
        if(gr[i].size()==t)
        {
            cout<<i+1<<" "<<x*2-max(dist0[i],dist1[i])<<endl;
        }
    }
    return 0;
}
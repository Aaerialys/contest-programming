#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int V,E,x,y,v;
bool vis[1000001];
queue<int> toV;
vector<int> gr[1000001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E;
    fori(0,E)
    {
        cin>>x>>y;
        gr[x].push_back(y);
    }
    cin>>x>>y;
    toV.push(x);
    vis[x]=true;
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(!vis[gr[v][i]])
            {
                vis[gr[v][i]]=true;
                toV.push(gr[v][i]);
            }
        }
    }
    if(vis[y])
    {
        cout<<"yes";
        return 0;
    }
    toV.push(y);
    vis[y]=true; vis[x]=false;
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(!vis[gr[v][i]])
            {
                vis[gr[v][i]]=true;
                toV.push(gr[v][i]);
            }
        }
    }
    if(vis[x])
        cout<<"no";
    else
        cout<<"unknown";
    return 0;
}
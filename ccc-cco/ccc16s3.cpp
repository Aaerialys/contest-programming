#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int n,m,a,b,rr,use;
vector<int> gr[100100];
vector<int> ngr[100100];
bool pho[100100];
bool rem[100100];
int dist[100100];
int dist0[100100];

bool dfs(int v,int prev)
{
    bool x=false;
    fori(0,gr[v].size())
    {
        if(gr[v][i]!=prev)
        {
            x=x|dfs(gr[v][i],v);
        }
    }
    if(pho[v])
        x=true;
    return rem[v]=x;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fori(0,m)
    {
        cin>>a;
        pho[a]=true;
        rr=a;
    }
    fori(0,n-1)
    {
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(rr,-1);
    fori(0,n)
    {
        if(rem[i])
            use++;
        forj(0,gr[i].size())
        {
            if(rem[i]&&rem[gr[i][j]])
                ngr[i].push_back(gr[i][j]);
        }
    }
    queue<int> toV;
    fori(0,n)
    {
        dist[i]=dist0[i]=INT_MAX;
    }
    toV.push(rr);
    dist[rr]=0;
    while(!toV.empty())
    {
        a=toV.front();
        toV.pop();
        fori(0,ngr[a].size())
        {
            b=ngr[a][i];
            if(dist[b]>dist[a]+1)
            {
                dist[b]=dist[a]+1;
                toV.push(b);
            }
        }
    }
    a=-1;
    fori(0,n)
    {
        if(a<dist[i]&&dist[i]!=INT_MAX)
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
        fori(0,ngr[a].size())
        {
            b=ngr[a][i];
            if(dist0[b]>dist0[a]+1)
            {
                dist0[b]=dist0[a]+1;
                toV.push(b);
            }
        }
    }
    a=-1;
    fori(0,n)
    {
        a=max(a+1,dist0[i]+1)-1;
    }
    cout<<2*use-a-2;
    return 0;
}
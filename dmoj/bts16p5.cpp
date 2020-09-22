#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,ch,w,a,b,c,t,val[10001],vsum[10001],wsum[10001];
vector<pair<int,int>> gr[10001];

void tre(int v,int p)
{
    vsum[v]=val[v];
    fori(0,gr[v].size())
    {
        if(gr[v][i].first!=p)
        {
            tre(gr[v][i].first,v);
            vsum[v]+=vsum[gr[v][i].first];
            wsum[v]+=wsum[gr[v][i].first];
        }
        else
            wsum[v]+=gr[v][i].second;
    }
    if(vsum[v]>=ch&&wsum[v]<=w)
        t++;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>ch>>w;
    fori(0,n)
        cin>>val[i];
    fori(1,n)
    {
        cin>>a>>b>>c; a--; b--;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    tre(0,-1);
    if(vsum[0]>=ch&&wsum[0]<=w)
        t--;
    cout<<t;
    return 0;
}
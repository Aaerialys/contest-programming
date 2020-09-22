#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,q,v;
    long long m,x,a;
    cin>>V;
    int city[V][2];
    long long gr[V][V];
    for(int i=0;i<V;i++)
    {
        cin>>city[i][0]>>city[i][1];
        for(int j=0;j<i;j++)
        {
            a=pow(city[j][0]-city[i][0],2)+pow(city[j][1]-city[i][1],2);
            gr[i][j]=a;
            gr[j][i]=a;
        }
    }
    cin>>x>>q;
    x--;
    long long dist[V];
    bool visit[V]={false};
    for(int i=0;i<V;i++)
    {
        dist[i]=LLONG_MAX;
        gr[i][i]=LLONG_MAX;
    }
    dist[x]=0;
    for(int i=0;i<V;i++)
    {
        m=LLONG_MAX;
        for(int j=0;j<V;j++)
        {
            if(m>dist[j]&&visit[j]==false)
            {
                m=dist[j];
                v=j;
            }
        }
        visit[v]=true;
        for(int j=0;j<V;j++)
        {
            if(dist[j]>dist[v]+gr[v][j]&&gr[v][j]!=LLONG_MAX)
            {
                dist[j]=dist[v]+gr[v][j];
            }
        }
    }
    sort(dist,dist+V);
    for(int i=0;i<q;i++)
    {
        cin>>x;
        cout<<upper_bound(dist,dist+V,x)-dist<<"\n";
    }
    return 0;
}
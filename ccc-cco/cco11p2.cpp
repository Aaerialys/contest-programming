#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int s,n,m,v1,v2,a,b,c,d,x[3];
    cin>>s>>n>>m;
    vector<int> gr0[n];
    vector<int> gr1[n];
    vector<int> gr2[n];
    fori(0,m)
    {
        cin>>a>>b>>c>>d;
        gr0[a].push_back(b);
        gr0[b].push_back(a);
        gr1[a].push_back(c);
        gr1[b].push_back(c);
        gr2[a].push_back(c*d);
        gr2[b].push_back(c*d);
    }
    queue<int> toVa;
    queue<int> toVb;
    int dist[n][s+1];
    fori(1,n)
        forj(0,s+1)
            dist[i][j]=INT_MAX;
    fori(0,s+1)
        dist[0][i]=0;
    toVa.push(0);
    toVb.push(0);
    while(!toVa.empty())
    {
        v1=toVa.front();
        v2=toVb.front();
        toVa.pop();
        toVb.pop();
        fori(0,gr0[v1].size())
        {
            a=gr0[v1][i];
            b=gr1[v1][i];
            c=gr2[v1][i];
            if(v2+c<=s&&dist[a][v2+c]>dist[v1][v2]+b)
            {
                forj(v2+c,s+1)
                {
                    dist[a][j]=min(dist[a][j],dist[v1][v2]+b);
                }
                toVa.push(a);
                toVb.push(v2+c);
            }
        }
    }
    if(dist[n-1][s]==INT_MAX)
        cout<<-1;
    else
        cout<<dist[n-1][s];
    return 0;
}
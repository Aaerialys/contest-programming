#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const long long M=LLONG_MAX/4;
long long n,q,a,b,c,u,v,dist[101][101][101];
vector<pair<long long,long long>> gr[101];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>> > toV;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        forj(0,n)
        {
            cin>>a;
            if(a!=0)
                gr[i].push_back({a,j});
        }
    }
    fori(0,n)
    {
        forj(0,n)
            dist[i][j][1]=M;
        dist[i][i][1]=0;
        toV.push(make_pair(0,i));
        while(!toV.empty())
        {
            u=toV.top().first; v=toV.top().second;
            toV.pop();
            if(u>dist[i][v][1]) continue;
            forj(0,gr[v].size())
            {
                if(dist[i][gr[v][j].second][1]>dist[i][v][1]+gr[v][j].first)
                {
                    dist[i][gr[v][j].second][1]=dist[i][v][1]+gr[v][j].first;
                    toV.push(make_pair(dist[i][gr[v][j].second][1],gr[v][j].second));
                }
            }
        }
    }
    fori(2,n)
    {
        forj(0,n)
            fork(0,n)
            {
                if(j==k)continue;
                dist[j][k][i]=M;
                for(int l=0;l<n;l++)
                    dist[j][k][i]=min(dist[j][k][i],max(dist[j][l][i-1],dist[l][k][1]));
            }
    }
    cin>>q;
    fori(0,q)
    {
        cin>>a>>b>>c; a--; b--;
        if(dist[a][b][c]==M)
            cout<<"0\n";
        else
            cout<<dist[a][b][c]<<"\n";
    }
    return 0;
}
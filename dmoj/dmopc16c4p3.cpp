#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
bool sell[100001][101];
int dist[100001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> close[101];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,q,a,b;
    char ch;
    cin>>n>>q;
    fori(0,n)
    {
        cin>>a;
        dist[i]=a;
    }
    fori(0,q)
    {
        cin>>a>>b;
        a--;
        sell[a][b]=true;
        close[b].push(make_pair(dist[a],a));
    }
    cin>>q;
    fori(0,q)
    {
        cin>>ch;
        if(ch=='A')
        {
            cin>>a>>b;
            a--;
            sell[a][b]=true;
            close[b].push(make_pair(dist[a],a));
        }
        if(ch=='S')
        {
            cin>>a>>b;
            a--;
            sell[a][b]=false;
        }
        if(ch=='E')
        {
            cin>>a>>b;
            a--;
            dist[a]=b;
            fori(0,101)
                sell[a][i]=false;
        }
        if(ch=='Q')
        {
            cin>>a;
            while(!close[a].empty()&&(sell[close[a].top().second][a]==false||close[a].top().first!=dist[close[a].top().second]))
                close[a].pop();
            if(close[a].empty())
                cout<<"-1\n";
            else
            {
                cout<<close[a].top().second+1<<"\n";
            }
        }
    }
    return 0;
}
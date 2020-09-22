#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;//a graph problem

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,K,s,t,a,b,c,d,sum=0;
    vector<int> list;
    queue<int> toV;
    cin>>n>>m>>K>>s>>t;
    vector<pair<int,int>>first[n];
    vector<pair<int,int>>last[n];
    int dist[n];
    s--;
    t--;
    list.push_back(0);
    list.push_back(K-1);
    fori(0,m)
    {
        cin>>a>>b>>c>>d;
        a--;
        b--;
        c--;
        first[a].push_back(make_pair(b,c));
        last[a].push_back(make_pair(b,d));
        list.push_back(c);
        list.push_back(d);
    }
    sort(list.begin(),list.end());
    d=list.size()-1;
    fori(0,d)
    {
        a=list[i];
        forj(0,n)
            dist[j]=INT_MAX;
        dist[s]=0;
        toV.push(s);
        while(!toV.empty())
        {
            b=toV.front();
            toV.pop();
            forj(0,first[b].size())
            {
                if(a>=first[b][j].second&&a<last[b][j].second&&dist[first[b][j].first]>dist[b]+1)
                {
                    dist[first[b][j].first]=dist[b]+1;
                    toV.push(first[b][j].first);
                }
            }
        }
        if(dist[t]!=INT_MAX)
        {
            sum+=list[i+1]-a;
        }
    }
    cout<<sum<<endl;
    return 0;
}
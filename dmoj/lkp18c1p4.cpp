#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long V,E,a,b,c;
typedef pair<long long,int> pii;
vector<pii> gr[100100];
vector<int> en[100100];
priority_queue<pii,vector<pii>,greater<pii> > toVisit;
int v,u;
long long dist[100100];

long long dk(int xx)
{
    fori(0,V)
        dist[i]=LLONG_MAX/4;
    dist[a]=0;
    toVisit.push(make_pair(0,a));
    while(!toVisit.empty())
    {
        u=toVisit.top().first;
        v=toVisit.top().second;
        toVisit.pop();
        if(u>dist[v])
            continue;
        for(int i=0;i<gr[v].size()&&en[v][i]<xx;i++)
        {
            if(dist[gr[v][i].second]>dist[v]+gr[v][i].first)
            {
                dist[gr[v][i].second]=dist[v]+gr[v][i].first;
                toVisit.push(make_pair(dist[gr[v][i].second],gr[v][i].second));
            }
        }
    }
    return dist[b];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E;
    fori(0,E)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        gr[a].push_back(make_pair(c,b));
        gr[b].push_back(make_pair(c,a));
        en[a].push_back(i);
        en[b].push_back(i);
    }
    cin>>a>>b>>c;
    a--;
    b--;
    if(dk(E)>c)
    {
        cout<<-1;
        return 0;
    }
    int lo = 1, hi = E, ans = E+1,mid;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(dk(mid)<=c){ ans=mid; hi = mid-1;}
        else lo = mid+1;
    }
    cout<<ans;
    return 0;
}
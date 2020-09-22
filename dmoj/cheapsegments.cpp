#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

struct event
{
    int x,v,t,i,l;
};
bool cmp(event a,event b)
{
    return a.x<b.x;
}

int n,q,a,b,c;
pair<pair<int,int>,int> ans[18][200010],xx;
vector<int> cord;
vector<event> evt;
vector<pair<int,int>> oevt;
multiset<pair<pair<int,int>,int>> val;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(1,n+1)
    {
        cin>>a>>b>>c; b++;
        evt.push_back({a,c,0,i,b-a}); evt.push_back({b,c,1,i,b-a});
        oevt.push_back({a,b-1});
        cord.push_back(a); cord.push_back(b);
    }
    evt.push_back({0,INT_MAX,0,-1,INT_MAX}); evt.push_back({INT_MAX,INT_MAX,1,-1,INT_MAX}); cord.push_back(0); cord.push_back(INT_MAX);
    sort(cord.begin(),cord.end()); sort(evt.begin(),evt.end(),cmp);
    fori(0,evt.size())
    {
        if(evt[i].t==0)
            val.insert({{evt[i].v,evt[i].l},evt[i].i});
        if(evt[i].t==1)
            val.erase(val.find({{evt[i].v,evt[i].l},evt[i].i}));
        ans[0][i]=*val.begin();
    }
    fori(1,18)
        forj(0,200010-(1<<i)+1)
                ans[i][j]=max(ans[i-1][j],ans[i-1][j+(1<<(i-1))]);
    cin>>q;
    fori(0,q)
    {
        cin>>a>>b; xx={{0,0},-1}; a--; b--;
        if(oevt[a].first>oevt[b].first)
            swap(a,b);
        if(oevt[a].second>oevt[b].second)
        {
            a=oevt[a].first-1;
            b=oevt[b].second+1;
        }
        else
        {
            a=oevt[a].first;
            b=oevt[b].second;
        }
        a=upper_bound(cord.begin(),cord.end(),a)-cord.begin()-1; b=upper_bound(cord.begin(),cord.end(),b)-cord.begin()-1;
       // forj(a,b+1)
         //   xx=max(xx,ans[j]);

        c=log2(b-a+1);
        cout<<max(ans[c][a],ans[c][b-(1<<c)]).second<<"\n";
    }
    return 0;
}
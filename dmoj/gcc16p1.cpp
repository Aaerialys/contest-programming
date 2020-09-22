#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int M=1e6;
vector<pair<int,int>> ev;
long long n,a,c,x,y,pos,t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>a>>c;
    fori(0,a)
    {
        cin>>x>>y;
        ev.push_back({x,1});
        ev.push_back({y+1,2});
    }
    fori(0,c)
    {
        cin>>x>>y;
        ev.push_back({x,0});
        ev.push_back({y+1,3});
    }
    sort(ev.begin(),ev.end());
    fori(0,ev.size())
    {
        x=ev[i].first; y=ev[i].second;
        if(pos>0)
        {
            t+=ev[i].first-ev[i-1].first;
        }
        if(ev[i].second==0)
            pos-=M;
        if(ev[i].second==3)
            pos+=M;
        if(ev[i].second==1)
            pos++;
        if(ev[i].second==2)
            pos--;
    }
    cout<<t;
    return 0;
}
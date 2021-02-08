#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

const int N=500010;
ll T,n,t,x,y;
pair<pii,int> p[N];
vector<pair<int,pii>> sub;
vector<int> team;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("hokej.in.7", "r", stdin);
    cin>>T>>n;
    fori(0,n)
    {
        cin>>p[i].pf.pf>>p[i].pf.ps;
        p[i].ps=i+1; p[i].pf.pf*=-1;
    }
    sort(p,p+n);
    for(int i=0;i<n&&x<T*6;i++)
    {
        t-=min(p[i].pf.ps,T*6-x)*p[i].pf.pf;
        //y=team.size();
        if(p[i].pf.ps>=T&&x<=T*6-p[i].pf.ps)
        {
            team.push_back(p[i].ps);
            x+=p[i].pf.ps;
            continue;
        }
        if(x%T)
            sub.push_back({x%T,{y,p[i].ps}});
        else
            team.push_back(p[i].ps);
        if(T-x%T<p[i].pf.ps&&T*6-x>=p[i].pf.ps)
            team.push_back(p[i].ps);
        x+=p[i].pf.ps;
        y=p[i].ps;
    }
    sort(sub.begin(),sub.end());
    cout<<t<<"\n";
    for(auto i:team)
        cout<<i<<" ";
    cout<<"\n"<<sub.size()<<"\n";
    for(auto i:sub)
        cout<<i.pf<<" "<<i.ps.pf<<" "<<i.ps.ps<<"\n";
    return 0;
}
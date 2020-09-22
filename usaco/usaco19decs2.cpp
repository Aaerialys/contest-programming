#include <bits/stdc++.h>
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define pf first
#define ps second
#define pb push_back
using namespace std; typedef long long ll; typedef pair<int,int> pii;
const int N=100010;
vector<pii> ps,ng,ts;
int n,L,x,y,z,w[N],tim[N],s1[N],s2[N],T;
ll t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("meetings.in", "r", stdin); freopen("meetings.out", "w", stdout);
    cin>>n>>L;
    fori(0,n)
    {
        cin>>w[i]>>x>>y; z+=w[i];
        if(y==1)
            ps.pb({x,i});
        else
            ng.pb({x,i});
    }
    sort(ps.begin(),ps.end()); sort(ng.begin(),ng.end());
    x=0;
    fori(0,ps.size())
    {
        for(;x<ng.size()&&ng[x].pf<ps[i].pf;x++);
        if(i<ng.size()-x)
        {
            tim[ps[i].ps]=ng[x+i].pf;
        }
        else
        {
            tim[ps[i].ps]=L-ps[i-(ng.size()-x)].pf;
        }
    }
    x=0;
    fori(0,ng.size())
    {
        for(;x<ps.size()&&ps[x].pf<ng[i].pf;x++);
        if(ng.size()-i-1<x)
        {
            tim[ng[i].ps]=L-ps[x-(ng.size()-i)].pf;
        }
        else
        {
            tim[ng[i].ps]=ng[i+x].pf;
        }
    }
    fori(0,ps.size())
        ts.push_back({tim[ps[i].ps],w[ps[i].ps]});
    fori(0,ng.size())
        ts.push_back({tim[ng[i].ps],w[ng[i].ps]});
    sort(ts.begin(),ts.end());
    for(auto i:ts)
    {
        T=max(T,i.pf);
        t+=i.ps;
        if(t*2>=z)
            break;
    }
    y=x=0; t=0; T*=2;
    fori(0,ps.size())
    {
        for(;x<ng.size()&&ng[x].pf<=ps[i].pf+T;x++);
        for(;y<ng.size()&&ng[y].pf<=ps[i].pf;y++);
        t+=x-y;
    }
    x=y=0;
    fori(0,ng.size())
    {
        for(;x<ps.size()&&ps[x].pf<=ng[i].pf;x++);
        for(;y<ps.size()&&ps[y].pf<ng[i].pf-T;y++);
        t+=x-y;
    }
    cout<<t/2;
    return 0;
}
/**

*/

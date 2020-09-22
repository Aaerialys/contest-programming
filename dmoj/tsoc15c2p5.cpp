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
typedef pair<int,int> pii;

pair<pii,pii> beb[50001];
int n,s,q,x;

bool cmp(pair<pii,pii> a,pair<pii,pii> b)
{
    if(a.pf.pf==b.pf.pf)
    {
        if(a.pf.pf>=s)
        {
            if(a.ps.pf==b.ps.pf)
                return a.ps.ps<b.ps.ps;
            return a.ps.pf<b.ps.pf;
        }
        else
        {
            if(a.pf.ps==b.pf.ps)
                return a.ps.ps<b.ps.ps;
            return a.pf.ps<b.pf.ps;
        }
    }
    return a.pf.pf<b.pf.pf;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>s>>n;
    fori(0,n)
    {
        cin>>beb[i].pf.pf>>beb[i].pf.ps>>beb[i].ps.pf;
        beb[i].ps.ps=i+1;
    }
    cin>>q;
    sort(beb,beb+n,cmp); reverse(beb,beb+n);
    fori(0,q)
    {
        cin>>x; x--;
        cout<<beb[x].ps.ps<<"\n";
    }
    return 0;
}
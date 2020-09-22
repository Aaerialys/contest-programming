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

const int N=1000010;
ll n,m,q,a,b,dl,pl,md[N],t;
unordered_map<ll,ll> day;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m>>q; pl=1000000; dl=0; day[0]=pl;
    fori(0,q)
    {
        cin>>a>>b; a=n-a;
        if(day.count(a))
            day[a]=min(day[a],b);
        else
            day[a]=b;
        if(a!=dl)
        {
            day[a]=min(day[a],pl);
            md[pl]+=max(0LL,a-dl-1);
        }
        dl=a; pl=b;
    }
    a=n-1;
    if(a!=dl)
    {
        if(day.count(a))
            day[a]=min(day[a],pl);
        else
            day[a]=pl;
        md[pl]+=max(0LL,a-dl-1);
    }
    for(auto i:day)
        md[i.ps]++;
    fori(0,N)
    {
        t+=min(md[i],m)*i;
        m-=md[i];
        if(m<=0)
            break;
    }
    cout<<t<<"\n";
    return 0;
}
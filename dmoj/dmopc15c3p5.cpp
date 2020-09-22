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

ll v[40],n,x,y,t;
unordered_map<ll,ll> way;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>x>>y; n=x+y;
    fori(0,n)
        cin>>v[i];
    fori(0,x)
        v[i]=-v[i];
    fori(0,1<<n/2)
    {
        x=0;
        forj(0,n/2)
            if(i&(1<<j))
                x+=v[j];
        way[x]++;
    }
    fori(0,1<<(n+1)/2)
    {
        x=0;
        forj(0,(n+1)/2)
            if(i&(1<<j))
                x+=v[j+(n/2)];
        t+=way[-x];
    }
    cout<<t-1;
    return 0;
}
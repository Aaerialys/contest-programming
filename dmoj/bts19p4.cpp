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

const int N=200010;
ll n,m,v[N],x,ls,rs,t=INF;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m;
    fori(0,n)
        cin>>v[i];
    sort(v,v+n);
    fori(0,n)
        v[i+n]=v[i]+m;
    v[2*n]=INF;
    for(;v[x]<v[0]+(m+1)/2;x++)
        ls+=v[x];
    fori(x,n)
        rs+=v[i];
    fori(0,n)
    {
        t=min(t,ls-(x-i)*v[i]+(n+i-x)*v[i+n]-rs);
        ls-=v[i];
        for(;v[x]<v[i+1]+(m+1)/2;x++)
        {
            ls+=v[x];
            rs-=v[x];
        }
        rs+=v[i+n];
    }
    cout<<t;
    return 0;
}
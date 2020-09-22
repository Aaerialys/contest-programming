#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(ll i=a;i<b;i++)
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

const int N=100010;

ll n,q,l,r,sub[N],p[N],t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    fori(0,n)
        cin>>p[i];
    fori(0,q)
    {
        cin>>l>>r; l--; r--;
        sub[l]++; sub[r+1]--;
    }
    fori(1,n)
        sub[i]+=sub[i-1];
    sort(sub,sub+n); reverse(sub,sub+n); sort(p,p+n);
    fori(0,n)
        t+=p[i]*sub[i];
    cout<<t;
    return 0;
}
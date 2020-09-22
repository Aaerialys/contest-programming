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

ll n,m,k,h[200010],s,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>m>>n>>k;
    fori(0,k)
        cin>>h[i];
    sort(h,h+k); reverse(h,h+k);
    fori(0,k)
        s+=h[i];
    fori(0,k/m)
        t+=h[i]*m+m*(m-1)/2;
    t+=h[k/m]*(k%m)+(k%m)*(k%m-1)/2;
    cout<<t-s;
    return 0;
}
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

int n,m,x[1501],t;
unordered_map<int,int> h;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m;
    fori(0,n)
    {
        cin>>x[i];
        forj(0,i)
            h[x[i]-x[j]]++;
    }
    fori(0,m)
    {
        cin>>x[i];
        forj(0,i)
            t+=h[x[i]-x[j]];
    }
    cout<<t;
    return 0;
}
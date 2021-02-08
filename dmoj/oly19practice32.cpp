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

int n,k,s;
pair<pii,int> x[50010];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>k;
    fori(0,n)
    {
        cin>>x[i].pf.pf>>x[i].pf.ps;
        x[i].ps=i+1;
    }
    sort(x,x+n); s=n-1;
    fori(n-k,n)
        if(x[s].pf.ps<x[i].pf.ps)
            s=i;
    cout<<x[s].ps;
    return 0;
}
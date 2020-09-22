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

int n,k,x;
pair<pii,int> s[50001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>k;
    fori(0,n)
    {
        cin>>s[i].pf.pf>>s[i].pf.ps;
        s[i].ps=i;
    }
    sort(s,s+n); x=n-k;
    fori(n-k,n)
        if(s[x].pf.ps<s[i].pf.ps)
            x=i;
    cout<<s[x].ps+1;
    return 0;
}
//computing tournament
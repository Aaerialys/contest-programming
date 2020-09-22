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

const int N=20010;
int n,e,a[1010],b[1010],dp[2][N],t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>e;
    fori(1,n)
        cin>>a[i]>>b[i];
    fori(e,N)
        dp[0][i]=-inf;
    fori(1,n)
    {
        forj(1,N)
            dp[1-i%2][j]=max(dp[1-i%2][j]+j,dp[1-i%2][j-1]);
        forj(0,b[i])
            dp[i%2][j]=max(dp[1-i%2][j+a[i]]-j,dp[1-i%2][a[i]-1]);
        forj(b[i],a[i]+b[i])
            dp[i%2][j]=dp[1-i%2][j-b[i]]-j+b[i];
        forj(a[i]+b[i],N)
            dp[i%2][j]=dp[1-i%2][j]-j;
    }
    fori(0,N)
        t=max(t,dp[1-n%2][i]+i);
    cout<<t;
    return 0;
}
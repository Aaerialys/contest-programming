#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,t,v[16],dp[16][1000100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("boring.14.in", "r", stdin);
    cin>>n>>t;
    fori(1,n+1)
        cin>>v[i];
    dp[0][0]=1;
    fori(1,n+1)
        forj(0,t+1)
            dp[i][j]=dp[i-1][j]+((j>=v[i])? dp[i-1][j-v[i]]: 0);
    cout<<dp[n][t];
    return 0;
}
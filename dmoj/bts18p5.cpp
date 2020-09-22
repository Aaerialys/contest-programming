#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,dp[2010][2010],book[2010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(1,n+1)
        cin>>book[i];
    fori(1,n+1)
        dp[1][i]=(dp[1][i-1]+book[i])%998244353;
    fori(2,n+1)
        forj(i,n+1)
            dp[i][j]=(dp[i-1][j-1]*book[j]+dp[i][j-1])%998244353;
    fori(1,n+1)
        cout<<(dp[i][n]+998244353)%998244353<<" ";
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,dp[100100][2],v[100100],t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(1,n+1)
        cin>>v[i];
    dp[1][0]=v[1]; dp[1][1]=-v[1]; dp[2][0]=v[2]+v[1]; dp[2][1]=-v[2]-v[1];
    fori(3,n+1)
    {
        dp[i][0]=max(dp[i-1][0]+v[i],dp[i-1][1]+v[i]);
        dp[i][1]=max(dp[i-1][0]-2*v[i-1]-v[i],dp[i-1][1]+2*v[i-1]-v[i]);
    }
    cout<<max(dp[n][0],dp[n][1]);
    return 0;
}
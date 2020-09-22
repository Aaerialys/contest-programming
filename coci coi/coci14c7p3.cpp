#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t=INT_MAX;
    cin>>n;
    int dif[n][3];
    int dp[n][3];
    int o[3]={0,1,2};
    fori(0,3)
    {
        forj(0,n)
        {
            cin>>dif[j][i];
        }
    }
    fori(0,6)
    {
        dp[0][0]=dif[0][o[0]];
        fori(1,n)
        {
            dp[i][0]=dp[i-1][0]+dif[i][o[0]];
        }
        dp[0][1]=INT_MAX/2;
        fori(1,n)
        {
            dp[i][1]=min(dp[i-1][1],dp[i-1][0])+dif[i][o[1]];
        }
        dp[1][2]=INT_MAX;
        fori(2,n)
        {
            dp[i][2]=min(dp[i-1][2],dp[i-1][1])+dif[i][o[2]];
        }
        next_permutation(o,o+3);
        t=min(t,dp[n-1][2]);
    }
    cout<<t;
    return 0;
}
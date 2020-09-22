#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,numb[300000],dp[2][300010],m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    forj(0,300010)
        dp[0][j]=INT_MAX/4;
    cin>>n;
    fori(0,n)
        cin>>numb[i];
    fori(1,59)
    {
        forj(0,n)
        {
            dp[1][j]=INT_MAX/4;
            if(numb[j]==i)
                dp[1][j]=j+1;
            else if(dp[0][j]<INT_MAX/4&&dp[0][dp[0][j]]<=n)
                dp[1][j]=dp[0][dp[0][j]];
            if(dp[1][j]<INT_MAX/4)
                m=i;
            dp[0][j]=dp[1][j];
        }
    }
    cout<<m;
    return 0;
}
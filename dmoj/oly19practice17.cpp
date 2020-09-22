#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,x,val[100100],dp[100100][2];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        val[x]++;
    }
    fori(0,100100)
        val[i]*=i;
    fori(0,100100)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=max(dp[i-1][0]+val[i],dp[i-1][1]);
    }
    cout<<dp[100010][1];
    return 0;
}
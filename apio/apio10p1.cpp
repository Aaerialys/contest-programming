#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,sum[1000100],dp[1000100],w,a,b,c;

long long f(long long x)
{
    return a*x*x+b*x+c;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>a>>b>>c;
    fori(1,n+1)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
        dp[i]=LLONG_MIN;
    }
    fori(1,n+1)
        forj(w,i)
        {
            if(dp[i]<=dp[j]+f(sum[i]-sum[j]))
            {
                dp[i]=dp[j]+f(sum[i]-sum[j]);
                w=j;
            }
        }
    cout<<dp[n];
    return 0;
}
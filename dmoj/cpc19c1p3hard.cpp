#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,dp[1000100];
bool pos[1000100],res[1000100];
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(3,n+3)
        dp[i]=INT_MAX/2;
    cin>>in;
    fori(3,n+3)
        pos[i]=in[i-3]-'0';
    cin>>in;
    fori(3,n+3)
        res[i]=in[i-3]-'0';
    fori(3,n+3)
    {
        if(pos[i]==res[i])
            dp[i]=dp[i-1];
        if(res[i])
            dp[i]=min(dp[i],dp[i-1]+1);
        dp[i]=min(dp[i],dp[i-3]+!pos[i]+!pos[i-1]+!pos[i-2]+res[i]+res[i-1]+res[i-2]+1);
        if(i>3)
            dp[i]=min(dp[i],dp[i-4]+!pos[i]+!pos[i-1]+!pos[i-2]+!pos[i-3]+res[i]+res[i-1]+res[i-2]+res[i-3]+1);
    }
    cout<<dp[n+2];
    return 0;
}
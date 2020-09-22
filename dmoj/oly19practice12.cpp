#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=20010;
long long n,K,arr[N],dp[2][N],temp[2][N],a,b=1;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>K;
    fori(1,n+1)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    fori(1,K+1)
    {
        dp[b][0]=temp[b][0]=LLONG_MIN/4;
        forj(1,n+1)
        {
            temp[b][j]=max(temp[b][j-1],dp[a][j-1]-arr[j-1]);
            dp[b][j]=max(dp[b][j-1],temp[b][j]+arr[j]);
        }
        swap(a,b);
    }
    cout<<dp[a][n];
    return 0;
}
/**
dp[i][j]=with i subsequnces, up to j
dp_include[i][j]= with i subsequences, last subsequence must include j
*/
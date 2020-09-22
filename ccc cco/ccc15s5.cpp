#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,m,ex[102],pie[3010],dp[3010][102][102][2];

int solve(int p,int l,int r,int st)
{
    if(p<0)
        return 0;
    if(dp[p][l][r][st]>-1)
        return dp[p][l][r][st];
    dp[p][l][r][st]=solve(p-1,l,r,1);
    if(st==1)
        dp[p][l][r][st]=max(dp[p][l][r][st],solve(p-1,l,r,0)+pie[p]);
    if(l<=r)
        dp[p][l][r][st]=max(dp[p][l][r][st],solve(p,l+1,r,1));
    if(st==1&&l<=r)
        dp[p][l][r][st]=max(dp[p][l][r][st],solve(p,l,r-1,0)+ex[r]);
    return dp[p][l][r][st];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,3010)
        forj(0,102)
            fork(0,102)
                dp[i][j][k][0]=dp[i][j][k][1]=-1;
    cin>>n; n++; pie[0]=0;
    fori(1,n)
        cin>>pie[i];
    cin>>m;
    fori(0,m)
        cin>>ex[i];
    sort(ex,ex+m);
    cout<<solve(n-1,0,m-1,1);
    return 0;
}
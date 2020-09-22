#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,pos[5010],c[100100],dp[5010];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(1,5010)
        dp[i]=INT_MAX;
    fori(0,100100)
        c[i]=INT_MAX/2;
    cin>>n>>m;
    fori(1,n+1)
        cin>>pos[i];
    sort(pos+1,pos+n+1);
    fori(1,m+1)
        cin>>c[i];
    ford(i,m-1,1)
        c[i]=min(c[i],c[i+1]);
    fori(1,n+1)
        forj(1,i+1)
            dp[i]=min(dp[i],dp[j-1]+c[pos[i]-pos[j]+1]);
    cout<<dp[n];
    return 0;
}
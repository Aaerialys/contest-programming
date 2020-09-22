#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,dp[1010],h[1010],view[1010],a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fork(0,5)
    {
        cin>>n>>m;
        fori(1,n+1)
        {
            cin>>h[i];
            for(int j=i;j>=max(1,i-m)&&h[j]<=h[i];j--)
                view[i]=j-1;
        }
        fori(1,n+1)
        {
            dp[i]=INT_MAX; a=h[i];
            ford(j,i,max(1,i-m))
            {
                if(h[j]<a)
                    continue;
                a=h[j];
                dp[i]=min(dp[i],dp[view[j]]+1);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
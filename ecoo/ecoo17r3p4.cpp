#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int M=4010;
long long n,m,x,y,a,l[M],r[M],dp[21][M],sum[M],med[M];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fork(0,10)
    {
        fori(0,M)
            dp[0][i]=LLONG_MAX/3;
        dp[0][0]=0;
        cin>>n>>m;
        fori(1,n+1)
        {
            cin>>l[i]>>r[i];
            sum[i]=sum[i-1]+l[i]*r[i];
            med[i]=med[i-1]+r[i];
        }
        fori(1,m+1)
        {
            dp[i][0]=0;
            x=y=0;
            forj(1,n+1)
            {
                a=lower_bound(med,med+n,(med[j]+med[x])/2)-med;
                dp[i][j]=dp[i-1][x]+(sum[j]-sum[a]-l[a]*(med[j]-med[a]))+(l[a]*(med[a]-med[x])-sum[a]+sum[x]);
                for(x=y;x<j;x++)
                {
                    a=lower_bound(med,med+n,(med[j]+med[x])/2)-med;
                    if(x<j&&dp[i-1][x]+(sum[j]-sum[a]-l[a]*(med[j]-med[a]))+(l[a]*(med[a]-med[x])-sum[a]+sum[x])<=dp[i][j])
                    {
                        dp[i][j]=dp[i-1][x]+(sum[j]-sum[a]-l[a]*(med[j]-med[a]))+(l[a]*(med[a]-med[x])-sum[a]+sum[x]);
                        y=x;
                    }
                    /*else
                    {
                        x--;
                        break;
                    }*/
                }
            }
        }
        cout<<dp[m][n]%1000000007<<"\n";
    }
    return 0;
}
/*dp table each new ice cream stand and visitor, check where to put new ice cream stand*/
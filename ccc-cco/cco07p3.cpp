#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=10010;
int T,p,b,w,pin[N],high[501][N],dp[501][N],x,ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("C.2.dat", "r", stdin);
    cin>>T; seto(high,-inf);
    while(T--)
    {
        cin>>p>>b>>w;
        fori(1,p+1)
            cin>>pin[i];
        fori(1,p+1)
            pin[i]+=pin[i-1];
        fori(1,b+1)
            forj(1,p+1)
            {
                x=max(0,j-w);
                high[i][j]=dp[i-1][x]+pin[j]-pin[x];
                if(j==p)
                    fork(x,j+1)
                        high[i][j]=max(high[i][j],dp[i-1][k]+pin[j]-pin[k]);
                else
                    fork(x,j+1)
                        high[i][j]=max(high[i][j],high[i-1][k]+pin[j]-pin[k]);
                dp[i][j]=max(dp[i][j-1],high[i][j]);
            }
        cout<<dp[b][p]<<"\n";
    }
    return 0;
}
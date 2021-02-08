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

const int N=2010,M=1e9+7;
ll dp[N][N],n,ss,ee;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>ss>>ee;
    dp[0][0]=1;
    fori(1,n+1)
        forj(0,n+1)
        {
            if(i==ss||i==ee)
                dp[i][j]=dp[i-1][j]+dp[i-1][j+1]*(j+1);
            else
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]*j*(j+1)+(i>ss)*(j+1)*dp[i-1][j+1]+(i>ee)*(j+1)*dp[i-1][j+1];
            dp[i][j]%=M;
        }
    cout<<dp[n-1][0];
    return 0;
}
/** big brain
dp[i][j]=dp[i-1][j-1] //(add i as independent block)
+ dp[i-1][j+1]*j*(j+1) //(use i to connect 2 blocks)
+ (i>start)*(j+1) // if connected to start
+ (i>end)*(j+1) // if connected to end

if(i=start or end)
    dp[i][j]= dp[i-1][j]+dp[i-1][j+1]*(j+1)
*/
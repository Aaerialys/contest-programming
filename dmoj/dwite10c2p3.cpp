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

int dp[9][9];
char ch;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        seto(dp,0);
        forj(1,9)
            ford(k,8,1)
            {
                cin>>ch;
                if(ch=='#')
                    dp[j][k]=-10000;
                else if(ch!='.')
                    dp[j][k]=ch-'0';
            }
        forj(1,9)
            fork(1,9)
                dp[j][k]+=max(dp[j-1][k],dp[j][k-1]);
        cout<<dp[8][8]<<"\n";
        cin>>s;
    }
    return 0;
}
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

const int N=100010;
ll n,K,a,b,rn[N];
double L,R=1000,C,ans,dp[N];
deque<int> best;

long double f(int j,int k)
{
    if(dp[k]-dp[j]<0)
        return inf;
    return (k-j)/(dp[k]-dp[j]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>K; a=0;
    while(true)
    {
        a++;
        C=(L+R)/2;
        best.clear(); best.push_back(0);
        fori(1,n+1)
        {
            while(best.size()>1&&f(best[0],best[1])<i)
                best.pop_front();
            dp[i]=dp[best[0]]-1.0*best[0]/i+1-C;
            rn[i]=rn[best[0]]+1;
            while(best.size()>1&&f(best[best.size()-1],i)<f(best[best.size()-2],best[best.size()-1]))
                best.pop_back();
            best.push_back(i);
        }
        if(rn[n]==K)
            break;
        if(rn[n]<K)
            R=C;
        if(rn[n]>K)
            L=C;
    }
    printf("%.9f",dp[n]+rn[n]*C);
    return 0;
}
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
ll n,k,sum[N],dp[N];
deque<int> best;

ll f(int i,int x)
{
    if(x==0)
        return sum[i]-sum[x];
    return sum[i]-sum[x]+dp[x-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>k;
    fori(1,n+1)
        cin>>sum[i];
    fori(1,n+1)
        sum[i]+=sum[i-1];
    fori(1,n+1)
    {
        while(!best.empty()&&best.front()<i-k)
            best.pop_front();
        while(!best.empty()&&f(i,best.back())<f(i,i-1))
            best.pop_back();
        best.push_back(i-1);
        dp[i]=f(i,best.front());
    }
    cout<<dp[n];
    return 0;
}
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

const int N=1e5+9;
int n,K,last[201][N],x;
ll sum[N],dp[2][N];
deque<ll> best;
stack<int> split;

long double f(int m,int a,int b)
{
    if(sum[b]==sum[a])
        return (dp[m][a]<dp[m][b])? -INF: INF;
    //double temp=(0.0+dp[m][a]-dp[m][b]-sum[a]*sum[a]+sum[b]*sum[b])/(sum[b]-sum[a]);
    return ((long double)0.0+dp[m][a]-dp[m][b]-sum[a]*sum[a]+sum[b]*sum[b])/(sum[b]-sum[a]);;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("63", "r", stdin);
    cin>>n>>K;
    fori(1,n+1)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    fori(1,K+1)
    {
        while(!best.empty())
            best.pop_back();
        best.push_back(i);
        forj(i+1,n+1)
        {
            while(best.size()>1&&f(1-i%2,best[0],best[1])<sum[j])
                best.pop_front();
            dp[i%2][j]=dp[1-i%2][best[0]]+sum[best[0]]*(sum[j]-sum[best[0]]);
            last[i][j]=best[0];
            while(best.size()>1&&f(1-i%2,best[best.size()-1],j)<f(1-i%2,best[best.size()-2],best[best.size()-1]))
                best.pop_back();
            best.push_back(j);
        }
        //cout<<i<<endl;
    }
    cout<<dp[K%2][n]<<"\n";
    x=n;
    ford(i,K,1)
    {
        x=last[i][x];
        split.push(x);
    }
    while(!split.empty())
    {
        cout<<split.top()<<" ";
        split.pop();
    }
    return 0;
}
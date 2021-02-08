#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

long long sq(long long x)
{
    return x*x;
}

const long long N=2000100;
long long n,l,sum[N],dp[N];
deque<long long> best;

double sup(long long j,long long k)
{
    return (dp[k]+sq(sum[k])-dp[j]-sq(sum[j]))/2/(sum[k]-sum[j]);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>l; l++;
    fori(1,n+1)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1]+1;
    }
    best.push_back(0);
    fori(1,n+1)
    {
        while(best.size()>1&&sup(best[0],best[1])<sum[i]-l)
            best.pop_front();
        dp[i]=dp[best[0]]+sq(sum[i]-sum[best[0]]-l);
        while(best.size()>1&&sup(best[best.size()-1],i)<sup(best[best.size()-2],best[best.size()-1]))
            best.pop_back();
        best.push_back(i);
    }
    cout<<dp[n];
    return 0;
}
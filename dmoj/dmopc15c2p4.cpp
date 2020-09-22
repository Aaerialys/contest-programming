#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

class pi
{
public:
    long long a,b,c;
};

bool cm(pi a,pi b)
{
    return a.b<b.b;
}

bool cmp(long long v,pi t)
{
    return v<=t.b;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,a;
    cin>>n;
    pi pt[n];
    fori(0,n)
    {
        cin>>pt[i].a>>pt[i].b>>pt[i].c;
        pt[i].b+=pt[i].a-1;
    }
    sort(pt,pt+n,cm);
    long long dp[n+1]={0};
    fori(1,n+1)
    {
        a=upper_bound(pt,pt+i,pt[i-1].a,cmp)-pt;
        dp[i]=max(dp[i-1],dp[a]+pt[i-1].c);
    }
    cout<<dp[n];
    return 0;
}
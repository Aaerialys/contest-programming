#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

bool cmp(long long v,pair<long long,long long> t)
{
    return v<=t.first;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,k,a;
    cin>>n>>k;
    pair<long long,long long> pt[k];
    fori(0,k)
    {
        cin>>pt[i].second>>pt[i].first;
    }
    sort(pt,pt+k);
    long long dp[k+1]={0};
    fori(1,k+1)
    {
        a=upper_bound(pt,pt+i,pt[i-1].second,cmp)-pt;
        dp[i]=max(dp[i-1],dp[a]+pt[i-1].first-pt[i-1].second+1);
    }
    cout<<n-dp[k]<<endl;
    return 0;
}
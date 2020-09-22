#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}

int dp[1000010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,x=0;
    cin>>n;
    pair<int,int> seg[n];
    fori(0,n)
    {
        cin>>seg[i].first>>seg[i].second;
    }
    sort(seg,seg+n,cmp);
    while(seg[x].second==0)
    {
        dp[0]++;
        x++;
    }
    n=seg[n-1].second;
    fori(0,n+1)
    {
        dp[i]=dp[i-1];
        while(i==seg[x].second)
        {
            dp[i]=max(dp[i],dp[seg[x].first]+1);
            x++;
        }
    }
    cout<<dp[n];
    return 0;
}
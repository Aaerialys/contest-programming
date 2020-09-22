#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,d[12],dp[12][10][2];

int fun(int pos,int prev,bool limit)
{
    if(pos<0)
        return 1;
    if(dp[pos][prev][limit]!=0)
    {
        return dp[pos][prev][limit];
    }
    int up=limit?d[pos]:9,ret=0;
    fori(0,up+1)
    {
        if(abs(i-prev)>=2)
           ret+=fun(pos-1,i,limit&&i==d[pos]);
    }
    return dp[pos][prev][limit]=ret;
}

int solve(int x)
{
    n=0;
    for(;x;x/=10)
        d[n++]=x%10;
    int cnt=0;
    fori(0,n)
    {
        int up=(i==n-1)? d[n-1]:9;
        forj(1,up+1)
        {
            cnt+=fun(i-1,j,i==n-1&&j==d[n-1]);
        }
    }
    return cnt;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int l,r;
    bool b;
    cin>>l>>r;
    if(l>r)
        swap(l,r);
    cout<<solve(r)-solve(l-1);
    return 0;
}
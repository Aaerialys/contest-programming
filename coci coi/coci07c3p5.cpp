#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

long long n,d[18],dp[18][200][2];
long long l,r,s,t;

long long fun(long long pos,long long sum,bool limit)
{
    if(pos<0)
        return sum==s?1:0;
    if(dp[pos][sum][limit]!=INT_MAX)
        return dp[pos][sum][limit];
    long long up=limit?d[pos]:9,ret=0;
    fori(0,up+1)
    {
        if(sum+i<=s)
            ret+=fun(pos-1,sum+i,limit&&i==d[pos]);
    }
    return dp[pos][sum][limit]=ret;
}

long long solve(long long x)
{
    n=0;
    fori(0,18)
        d[i]=0;
    for(;x;x/=10)
        d[n++]=x%10;
    fori(0,18)
        forj(0,200)
            fork(0,2)
                dp[i][j][k]=INT_MAX;
    return fun(n-1,0,1);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>r>>s;
    cout<<solve(r)-solve(l-1)<<"\n";
    //cout<<l<<" "<<r<<" "<<s<<"\n";
    solve(l);
    t=0;
    fori(0,n+1)
        t+=d[i];
    for(long long i=0;t>s;i++)
    {
        t-=d[i]-1;
        d[i]=0;
        long long j;
        for(j=i+1;d[j]==9;j++)
        {
            t-=d[j];
            d[j]=0;
        }
        d[j]++;
    }
    for(long long i=0;t<s;i++)
    {
        t+=9-d[i];
        d[i]=9;
        if(t>s)
        {
            d[i]-=t-s;
            t=s;
        }
    }
    t=0;
    fori(0,n+1)
    {
        t*=10;
        t+=d[n-i];
    }
    cout<<t<<endl;
    return 0;
}
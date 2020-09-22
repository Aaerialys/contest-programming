#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x);

using namespace std;

const long long N=2010;
long long n,L,T,sz,x0,z,ans[N][N][2],loc[N],t;

long long dp(long long l,long long r,long long s)
{
    if(ans[l][r][s]!=-1)
        return ans[l][r][s];
    if(r-l==sz)
        return ans[l][r][s]=0;
    ans[l][r][s]=INT_MAX/2;
    if(s)
    {
        if(l>0)
            ans[l][r][s]=(sz-r+l)*(loc[r]-loc[l-1])+dp(l-1,r,0);
        if(r<n-1)
            ans[l][r][s]=min(ans[l][r][s],(sz-r+l)*(loc[r+1]-loc[r])+dp(l,r+1,1));
    }
    else
    {
        if(l>0)
            ans[l][r][s]=(sz-r+l)*(loc[l]-loc[l-1])+dp(l-1,r,0);
        if(r<n-1)
            ans[l][r][s]=min(ans[l][r][s],(sz-r+l)*(loc[r+1]-loc[l])+dp(l,r+1,1));
    }
    return ans[l][r][s];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>L; T=1e8;
    fori(0,n)
    {
        cin>>loc[i]; loc[i]-=L;
        if(loc[i]==0)
            z=1;
    }
    if(z==0)
        n++;
    sort(loc,loc+n);
    x0=lower_bound(loc,loc+n,0)-loc;
    fori(n+z-1,n+z)
    {
        forj(0,N)
            fork(0,N)
                ans[j][k][0]=ans[j][k][1]=-1;
        sz=i;
        t=max(t,T*i-dp(x0,x0,1));
    }
    if(z)
        t+=T;
    cout<<T*(n-1)-t<<endl;
    return 0;
}
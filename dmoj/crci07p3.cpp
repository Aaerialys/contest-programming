#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int a[110],b[110],c[110],d[110],e[110],f[110],dp[1100000];
int n,m;

int pos(int x)
{
    int t=0,p,q;
    fori(0,n)
    {
        dp[0]=0;
        p=max(0,a[i]*x-b[i]);
        if(p>1000100)
            return false;
        forj(1,p+1)
        {
            dp[j]=min(dp[max(j-c[i],0)]+d[i],dp[max(j-e[i],0)]+f[i]);
        }
        t+=dp[p];
    }
    if(t>m)
        return false;
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    cin>>n>>m;
    fori(0,n)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i]>>f[i];
    }
    if(!pos(1))
    {
        cout<<0;
        return 0;
    }
    x=1<<20;
    y=1<<19;
    fori(0,20)
    {
        if(pos(x+1))
            x+=y;
        if(!pos(x))
            x-=y;
        y=y>>1;
    }
    cout<<x;
    return 0;
}
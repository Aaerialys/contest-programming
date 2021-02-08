#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,k,arr[300010],sum[300010],l,r=2e9,m,ans;

bool pos(long long x)
{
    long long mini=LLONG_MAX/4;
    fori(0,n)
    {
        sum[i]=arr[i]-x;
        if(i>0)
            sum[i]+=sum[i-1];
        if(i>=k)
            mini=min(mini,sum[i-k]);
        if(sum[i]>=mini)
            return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fori(0,n)
    {
        cin>>arr[i];
        arr[i]*=1000;
    }
    while(l!=r)
    {
        m=(l+r)/2;
        if(pos(m))
        {
            l=m+1;
            ans=m;
        }
        else
            r=m;
    }
    printf("%f",ans/1000.0);
    return 0;
}
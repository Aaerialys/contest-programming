#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,t,hap[100010],en[100010],l,r,mid,s,mm=LLONG_MAX/4,mod=998244353,a,b,c,e;

bool pos(long long x)
{
    s=0;
    fori(0,n)
        if(hap[i]>=x)
            s=min(mm,s+(hap[i]-x)/en[i]+1);
    e=(t-s)%mod;
    return s<=t;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t; t=min(t,mm-1);
    fori(0,n)
    {
        cin>>hap[i]>>en[i];
    }
    l=0; r=mm;
    while(l!=r)
    {
        mid=(l+r)/2;
        if(pos(mid))
            r=mid;
        else
            l=mid+1;
    }
    pos(r);
    s=0;
    fori(0,n)
    {
        if(r<=hap[i])
        {
            a=((hap[i]-r)/en[i]+1);
            b=hap[i]*2-(a-1)*en[i];
            if(b%2==1)
                a/=2;
            else
                b/=2;
            c=(a%mod)*(b%mod);
            s=(s+max(0LL,c%mod))%mod;
        }
    }
    s=s%mod+e*(max(0LL,r-1)%mod)%mod;
    cout<<s%mod<<"\n";
    return 0;
}
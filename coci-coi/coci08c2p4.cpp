#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=101;
long long n,m,T,l,r,mid,x,y,tx,ty,ans=INT_MAX,a[N],b[N],c[N],d[N];

int pick(int t)
{
    long long k=0,xx=0; tx=0;
    fori(0,n)
    {
        xx=max(0LL,(t-a[i])/b[i]);
        k+=xx;
        if(xx>0)
            tx=max(tx,xx*b[i]+a[i]);
    }
    return k;
}
int nut(int t)
{
    long long k=0,xx=0; ty=0;
    fori(0,m)
    {
        xx=max(0LL,(t-c[i])/d[i]);
        k+=xx;
        if(xx>0)
            ty=max(ty,xx*d[i]+c[i]);
    }
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>T>>n; r=T;
    fori(0,n)
    {
        cin>>a[i]>>b[i];
        a[i]-=b[i];
    }
    cin>>m;
    fori(0,m)
    {
        cin>>c[i]>>d[i];
        c[i]-=d[i];
    }
    while(l<r)
    {
        mid=(l+r)/2; x=pick(mid); y=nut(T-mid);
        if(x<y||(x==y&&tx+ty<T))
            l=mid+1;
        else
            r=mid;
        if(x<=y&&tx+ty==T&&x>=nut(T-mid-1))
            ans=min(ans,mid);

    }
    cout<<ans<<endl;
    return 0;
}
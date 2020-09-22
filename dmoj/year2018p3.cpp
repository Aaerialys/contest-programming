#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,m,k,l,r,mid,snow[100010],ans;

bool pos(long long x)
{
    long long upd[100010]={0},h[100010],t=0;
    fori(0,n)
    {
        if(i>0)
            upd[i]+=upd[i-1];
        h[i]=snow[i]+upd[i];
        if(h[i]<x)
        {
            t+=x-h[i];
            upd[i]+=x-h[i];
            if(i+m<=n)
                upd[i+m]-=x-h[i];
        }
    }
    if(t>k)
        return false;
    return true;

}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    fori(0,n)
        cin>>snow[i];
    r=3e9;
    while(l!=r)
    {
        mid=(l+r)/2;
        if(pos(mid))
        {
           l=mid+1;
           ans=mid;
        }
        else
            r=mid;
    }
    cout<<ans;
    return 0;
}
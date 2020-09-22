#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,x,y,m=LLONG_MAX,lmin[50001],lmax[50001],rmin[50001],rmax[50001];
pair<long long,long long> p1[50001],p2[50001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x>>y;
        p1[i].first=p2[i].second=x; p2[i].first=p1[i].second=y;
    }
    sort(p1,p1+n); sort(p2,p2+n);
    lmin[0]=lmax[0]=p1[0].second; rmin[n-1]=rmax[n-1]=p1[n-1].second;
    fori(1,n)
    {
        lmin[i]=min(lmin[i-1],p1[i].second);
        lmax[i]=max(lmax[i-1],p1[i].second);
        rmin[n-i-1]=min(rmin[n-i],p1[n-i-1].second);
        rmax[n-i-1]=max(rmax[n-i],p1[n-i-1].second);
    }
    fori(0,n-1)
    {
        m=min(m,(lmax[i]-lmin[i])*(p1[i].first-p1[0].first)+(rmax[i+1]-rmin[i+1])*(p1[n-1].first-p1[i+1].first));
    }
    lmin[0]=lmax[0]=p2[0].second; rmin[n-1]=rmax[n-1]=p2[n-1].second;
    fori(1,n)
    {
        lmin[i]=min(lmin[i-1],p2[i].second);
        lmax[i]=max(lmax[i-1],p2[i].second);
        rmin[n-i-1]=min(rmin[n-i],p2[n-i-1].second);
        rmax[n-i-1]=max(rmax[n-i],p2[n-i-1].second);
    }
    fori(0,n-1)
    {
        m=min(m,(lmax[i]-lmin[i])*(p2[i].first-p2[0].first)+(rmax[i+1]-rmin[i+1])*(p2[n-1].first-p2[i+1].first));
    }
    cout<<(rmax[0]-rmin[0])*(p2[n-1].first-p2[0].first)-m;
    return 0;
}
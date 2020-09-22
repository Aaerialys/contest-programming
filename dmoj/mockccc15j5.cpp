#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,m,a[100001],b[100001],x,y;
long long t;
pair<int,int> c[100001],d[100001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x>>y;
        c[i].first=d[i].second=x; c[i].second=d[i].first=y;
    }
    sort(c,c+n); sort(d,d+n);
    cin>>m;
    fori(0,m)
        cin>>a[i]>>b[i];
    fori(1,m)
    {
        if(a[i]==a[i-1])
        {
            x=max(b[i],b[i-1]); y=min(b[i],b[i-1]);
            t+=upper_bound(c,c+n,make_pair(a[i],x))-lower_bound(c,c+n,make_pair(a[i],y));
        }
        if(b[i]==b[i-1])
        {
            x=max(a[i],a[i-1]); y=min(a[i],a[i-1]);
            t+=upper_bound(d,d+n,make_pair(b[i],x))-lower_bound(d,d+n,make_pair(b[i],y));
        }
    }
    cout<<t;
    return 0;
}
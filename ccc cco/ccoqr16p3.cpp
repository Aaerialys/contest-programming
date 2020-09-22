#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

long long overlap(long long r1,long long c1,long long r2,long long c2)
{
    long long x,y,z,xx=0;
    y=r1;
    z=r2;
    if(c1>c2)
    {
        y=r2;
        z=r1;
    }
    x=min(max(y-(abs(c1-c2)),xx),z);
    return x*(x+1)/2;
}

bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
    return a.second<b.second||(a.second==b.second&&a.first<b.first);
}
long long n,m,r=0,c=0,t=0;
pair<long long,long long> bl[100010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("data_structure.8.in", "r", stdin);
    cin>>n>>m;
    fori(0,m)
    {
        cin>>bl[i].first>>bl[i].second;
        bl[i].first=n-bl[i].first+1;
    }
    sort(bl,bl+m,cmp); bl[m].second=INT_MAX;
    fori(0,m)
    {
        if(bl[i].second<bl[i+1].second)
        {
            t+=bl[i].first*(bl[i].first+1)/2;
            t-=overlap(bl[i].first,bl[i].second,r,c);
            if(bl[i].second-c+bl[i].first>r)
            {
                r=bl[i].first;
                c=bl[i].second;
            }
        }
    }
    cout<<t;
    return 0;
}
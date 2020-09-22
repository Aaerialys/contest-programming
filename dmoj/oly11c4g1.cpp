#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

long long n,m,K,ans,l,r,mid,a;
pair<long long,long long> c[50010];

long long pos(long long x)
{
    if(x==0)
        return 0;
    priority_queue<long long> red; red.push(LLONG_MIN);
    priority_queue<pair<long long,long long>> dif; dif.push({LLONG_MIN,50001});
    long long t=0,p=x-1,k=min(K,x);
    bool use[50010]={0};
    fori(0,x)
        dif.push({c[i].first-c[i].second,i});
    fori(x,n)
        red.push(-c[i].second);
    fori(0,x)
        t+=c[i].first;
    fori(0,k)
    {
        while(p>=x-k&&use[p])
            p--;
        if(c[p].first+red.top()>=dif.top().first)
        {
            t-=c[p].first+red.top();
            red.pop();
            red.push(-c[p].second);
            use[p]=true;
            p--;
        }
        else
        {
            t-=dif.top().first;
            use[dif.top().second]=true;
        }
        while(use[dif.top().second])
            dif.pop();
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>K>>m; r=n;
    fori(0,n)
        cin>>c[i].first>>c[i].second;
    sort(c,c+n);//*
    while(l!=r)
    {
        mid=(l+r)/2; a=pos(mid);
        if(a<m)
            l=mid+1;
        else
            r=mid;
        if(a<=m)
            ans=max(ans,mid);
    }
    fori(max(0LL,ans-100),min(n+1,ans+100))
        if(pos(i)<=m)
            ans=i;/*/
    fori(0,n+1)
        if(pos(i)>m)
        {
            cout<<i-1;
            return 0;
        }*/
    cout<<ans;
    return 0;
}
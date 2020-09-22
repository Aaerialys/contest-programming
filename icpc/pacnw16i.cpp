#include <bits/stdc++.h>
#define fori(i,a,b) for(long long i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,k,loc[1001],num[1001],t,x,o=INT_MAX;
pair<int,int> h[1001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    fori(i,0,n)
        cin>>h[i].first>>h[i].second;
    sort(h,h+n);
    fori(i,0,n)
    {
        loc[i]=h[i].first; num[i]=h[i].second;
        if(loc[i]>0)
            o=min(o,i);
        loc[i]=abs(loc[i]);
    }
    ford(i,n-1,o)
    {
        t+=num[i]/k*loc[i]; num[i]=num[i]%k;;
        if(num[i]>0)
        {
            t+=loc[i];
            if(i>o)
                num[i-1]-=k-num[i];
            num[i]=0;
        }
        if(i>o)
            num[i-1]+=num[i];
    }
    fori(i,0,o)
    {
        t+=num[i]/k*loc[i]; num[i]=num[i]%k;;
        if(num[i]>0)
        {
            t+=loc[i];
            num[i+1]-=k-num[i];
            num[i]=0;
        }
        num[i+1]+=num[i];
    }
    cout<<t*2<<endl;
    return 0;
}
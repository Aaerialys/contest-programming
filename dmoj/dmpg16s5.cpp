#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int NN=300010;

long long n,k,x,t,arr[NN],sum[NN];
deque<long long> mi;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fori(1,n+1)
        cin>>arr[i];
    fori(1,n+1)
        sum[i]=sum[i-1]+arr[i];
    fori(n+1,n*2+1)
        sum[i]=sum[i-1]+arr[i-n];
    fori(0,n*2+1)
    {
        while(!mi.empty()&&mi.back()>sum[i])
            mi.pop_back();
        mi.push_back(sum[i]);
        while(i-x>k)
        {
            if(mi.front()==sum[x])
                mi.pop_front();
            x++;
        }
        t=max(t,(long long)(sum[i]-mi.front()));
    }
    cout<<t;
    return 0;
}
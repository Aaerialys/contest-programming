#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,w,m1=0,m2=0;
    cin>>n>>w;
    long long temp[n];
    fori(0,n)
        cin>>temp[i];
    sort(temp,temp+n);
    cout<<max(temp[n-1],w)-min(temp[0],w);
    m1+=abs(temp[0]-w);
    fori(0,n/2)
    {
        m1+=max(temp[n-i-1]-temp[i],abs(temp[n-i-1]-w));
        if(n-i-1!=i+1)
            m1+=max(temp[n-i-1]-temp[i+1],abs(w-temp[i+1]));
    }
    m2+=abs(temp[n-1]-w);
    fori(0,n/2)
    {
        m2+=max(temp[n-i-1]-temp[i],abs(w-temp[i]));
        if(n-i-2!=i)
            m2+=max(temp[n-i-2]-temp[i],abs(temp[n-i-2]-w));
    }
    cout<<" "<<max(m1,m2);
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,ma[1000100],mi[1000100],arr[1000100];
long long t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>arr[i];
        if(i>0)
            ma[i]=ma[i-1];
        ma[i]=max(ma[i],arr[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i<n-1)
            mi[i]=mi[i+1];
        mi[i]=max(mi[i],arr[i]);
    }
    fori(0,n)
    {
        t+=max(0,min(ma[i],mi[i])-arr[i]);
    }
    cout<<t;
    return 0;
}
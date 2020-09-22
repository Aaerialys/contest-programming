#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
long long arr[100010];
long long n,m;

bool pos(long long t)
{
    long long x=0,a=1;
    fori(0,n)
    {
        if(arr[i]>t)
            return false;
        x+=arr[i];
        if(x>t)
        {
            a++;
            x=arr[i];
        }
    }
    if(a>m)
        return false;
    return true;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t=1LL<<46,x=t/2;
    cin>>n>>m;
    fori(0,n)
    {
        cin>>arr[i];
    }
    if(pos(0))
    {
        cout<<0;
        return 0;
    }
    fori(0,46)
    {
        if(pos(t-1))
            t-=x;
        else if(!pos(t))
            t+=x;
        x=(x>>1);
    }
    cout<<t<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,a[200010],b,t,m=INT_MAX,ma=INT_MAX,o;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>a[i];
    fori(0,n)
    {
        cin>>b;
        t+=min(a[i],b);
        if(b<a[i])
        {
            m=min(m,a[i]-b);
            o++;
        }
        else
            ma=min(ma,b-a[i]);
    }
    if(o%2)
        t+=min(m,ma);
    cout<<t;
    return 0;
}
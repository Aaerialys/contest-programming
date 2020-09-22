#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,h[51],s,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fork(0,5)
    {
        cin>>n; s=t=0;
        fori(0,n)
        {
            cin>>h[i];
            s+=h[i];
        }
        s/=n;
        fori(0,n)
            t+=max(0,h[i]-s);
        cout<<t<<endl;
    }
    return 0;
}
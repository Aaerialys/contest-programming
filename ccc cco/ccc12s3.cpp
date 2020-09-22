#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int f[1001],n,x,a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        f[x]++;
    }
    fori(0,1001)
        if(f[i]>f[a])
            a=i;
    fori(0,1001)
    {
        if(i!=a&&f[i]>f[b])
            b=i;
        if(i!=a&&f[i]==f[b]&&abs(a-i)>abs(a-b))
            b=i;
    }
    cout<<abs(a-b);
    return 0;
}
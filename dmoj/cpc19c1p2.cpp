#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,k,h[200100],x,m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    fori(0,n)
        cin>>h[i];
    sort(h,h+n);
    fori(0,n)
    {
        while(h[i]-h[x]>k)
            x++;
        m=max(m,i-x+1);
    }
    cout<<m;
    return 0;
}
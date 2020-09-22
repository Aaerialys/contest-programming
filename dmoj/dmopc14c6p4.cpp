#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,h,t=0,x;
    cin>>n>>m>>h;
    float bus[n];
    fori(0,n)
        cin>>bus[i];
    reverse(bus,bus+n);
    fori(0,n-1)
    {
        x=ceil((bus[i]-bus[i+1]-h)/m);
        if(x>0)
        {
            t+=x;
            bus[i+1]+=x*m;
        }
    }
    cout<<t;
    return 0;
}
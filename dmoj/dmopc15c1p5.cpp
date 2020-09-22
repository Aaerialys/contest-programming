#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,w,h,f[260][260],x,y,t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>w>>h>>n; w++; h++;
    fori(1,h)
        forj(1,w)
            cin>>f[i][j];
    fori(1,h)
        forj(1,w)
            f[i][j]+=f[i][j-1];
    fori(1,h)
        forj(1,w)
            f[i][j]+=f[i-1][j];
    fori(1,h)
    {
        y=i;
        x=n/i;
        forj(y,h)
            fork(x,w)
                t=max(t,f[j][k]-f[j][k-x]-f[j-y][k]+f[j-y][k-x]);
    }
    fori(1,w)
    {
        x=i;
        y=n/i;
        forj(y,h)
            fork(x,w)
                t=max(t,f[j][k]-f[j][k-x]-f[j-y][k]+f[j-y][k-x]);
    }
    cout<<t;
    return 0;
}
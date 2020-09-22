#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,x,y,h,w,t;
bool c[10001][10001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fori(0,m)
    {
        cin>>x>>y>>w>>h;
        c[x][y]^=1; c[x+w][y]^=1; c[x][y+h]^=1; c[x+w][y+h]^=1;
    }
    fori(0,n)
        forj(1,n)
            c[i][j]^=c[i][j-1];
    fori(1,n)
        forj(0,n)
            c[i][j]^=c[i-1][j];
    fori(0,n)
        forj(0,n)
            t+=c[i][j];
    cout<<t;
    return 0;
}
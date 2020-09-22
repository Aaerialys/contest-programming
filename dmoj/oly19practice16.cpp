#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,x[51][51];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
        forj(0,n)
            cin>>x[i][j];
    fori(0,n)
    {
        forj(0,n)
            cout<<x[n-j-1][n-i-1]<<" ";
        cout<<"\n";
    }
    return 0;
}
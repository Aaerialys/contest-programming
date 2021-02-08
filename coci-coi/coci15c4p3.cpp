#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,arr[1001][1001],x;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        forj(0,n)
            cin>>arr[i][j];
    fori(0,n)
    {
        x=0;
        forj(0,n)
            x=x|arr[i][j]|arr[j][i];
        cout<<x<<" ";
    }
    return 0;
}
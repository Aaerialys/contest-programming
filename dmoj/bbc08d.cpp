#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout<<2000<<"\n";
    fori(1,1001)
    {
        cout<<i<<" 1 "<<i<<" 2\n";
    }
    fori(0,1000)
    {
        cout<<1000-i<<" 1 "<<1000-i<<" 2\n";
    }
    return 0;
}
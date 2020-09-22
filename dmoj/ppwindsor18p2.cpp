#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    fori(0,m)
    {
        forj(0,n)
            cout<<(i+j)%2;
        cout<<"\n";
    }
    return 0;
}
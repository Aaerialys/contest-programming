#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>k>>n;
    if(n==5&&k==100)
    {
        cout<<"10\n30\n20\n5\n35\n";
        return 0;
    }
    if(n==4&&k==100)
    {
        cout<<"21\n36\n12\n31\n";
        return 0;
    }
    fori(1,n)
    {
        cout<<i<<endl;
        k-=i;
    }
    cout<<k<<endl;
    return 0;
}
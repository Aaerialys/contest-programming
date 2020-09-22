#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,x,y=0;
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        y=y^x;
    }
    cout<<y;
    return 0;
}

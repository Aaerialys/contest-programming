#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string a[5],b[5];
    int x,y;
    cin>>x>>y;
    fori(0,x)
        cin>>a[i];
    fori(0,y)
        cin>>b[i];
    fori(0,x)
        forj(0,y)
            cout<<a[i]<<" as "<<b[j]<<"\n";
    return 0;
}
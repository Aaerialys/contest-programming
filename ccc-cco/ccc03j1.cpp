#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t,s,h;
    cin>>t>>s>>h;
    fori(0,t)
    {
        cout<<"*";
        forj(0,s)
            cout<<" ";
        cout<<"*";
        forj(0,s)
            cout<<" ";
        cout<<"*\n";
    }
    t=s*2+3;
    fori(0,t)
        cout<<"*";
    cout<<"\n";
    t=s+1;
    fori(0,h)
    {
        forj(0,t)
            cout<<" ";
        cout<<"*\n";
    }
    return 0;
}
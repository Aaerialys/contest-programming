#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a>0&&b>0)
        cout<<1;
    else if(a>0)
        cout<<4;
    else if(b>0)
        cout<<2;
    else
        cout<<3;
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    if(a<=5)
        cout<<a/2+1;
    else
        cout<<(10-a)/2+1;
    return 0;
}
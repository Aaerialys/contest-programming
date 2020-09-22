#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    double n;
    long long x;
    cin>>n;
    x=ceil(sqrt(8*n+1)/2-0.5);
    cout<<(x*x*x+x)/2;
    return 0;
}
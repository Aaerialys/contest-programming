#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin>>n>>m;
    if(n>9)
        n=9;
    if(m>9)
        m=9;
    if(n+m<=9)
        cout<<"There are 0 ways to get the sum 10.";
    else if(n+m==10)
        cout<<"There is 1 way to get the sum 10.";
    else
        cout<<"There are "<<n+m-9<<" ways to get the sum 10.";
    return 0;
}
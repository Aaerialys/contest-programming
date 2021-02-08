#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x,k,a=0;
    cin>>x>>k;
    a=x;
    for(int i=0;i<k;i++)
    {
        x*=10;
        a+=x;
    }
    cout<<a;
    return 0;
}
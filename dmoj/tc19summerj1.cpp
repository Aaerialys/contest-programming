#include <bits/stdc++.h>

using namespace std;

int a,b;

int solve(int x)
{
    if(x==0)
        return 0;
    int y=solve(x/2);
    return (abs(y-b)<abs(x-b)? y:x);
}

int main() {
    cin>>a>>b;
    cout<<solve(a);
    return 0;
}
#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    float a,b;
    cin>>a>>b;
    a=pow(a,1.0/6);
    b=pow(b,1.0/6);
    cout<<floor(b)-ceil(a)+1;
    return 0;
}
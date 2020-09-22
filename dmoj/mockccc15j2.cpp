#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    float a,b,c,d;
    cin>>a>>b>>c;
    c/=100;
    d=ceil((b-a*(1-c)-0.5)/c);
    if(d<0)
    {
        d=0;
    }
    if(d>100)
    {
        cout<<"DROP THE COURSE";
    }
    else
    {
        cout<<d;
    }
    return 0;
}
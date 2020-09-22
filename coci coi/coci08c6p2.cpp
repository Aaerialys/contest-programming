#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    double x,y;
    cin>>x>>y;
    if(y==0)
    {
        if(x>=125)
            cout<<0.00<<" "<<31250/x;
        if(x<125)
            cout<<250-31250/(250-x)<<" "<<31250/(250-x);
    }
    else if(x==0)
    {
        if(y>=125)
            cout<<31250/y<<" "<<0.00;
        if(y<125)
            cout<<31250/(250-y)<<" "<<250-31250/(250-y);
    }
    else
    {
        if(x<=125)
            cout<<250-31250/y<<" "<<0.00;
        if(x>125)
            cout<<0.00<<" "<<250-31250/x;
    }
    return 0;
}
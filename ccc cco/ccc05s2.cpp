#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x=0,y=0,a,b,c,r;
    cin>>c>>r;
    cin>>a>>b;
    while(a!=0||b!=0)
    {
        x+=a;
        y+=b;
        if(x<0)
            x=0;
        if(y<0)
            y=0;
        if(x>c)
            x=c;
        if(y>r)
            y=r;
        cout<<x<<" "<<y<<endl;
        cin>>a>>b;
    }
    return 0;
}
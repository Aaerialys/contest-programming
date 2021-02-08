#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a=100,b=100,n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x<y)
            a-=y;
        if(x>y)
            b-=x;
    }
    cout<<a<<endl<<b;
    return 0;
}
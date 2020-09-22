#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a<2)
        cout<<"Before";
    if(a>2)
        cout<<"After";
    if(a==2)
    {
        if(b<18)
            cout<<"Before";
        if(b>18)
            cout<<"After";
        if(b==18)
            cout<<"Special";
    }
    return 0;
}
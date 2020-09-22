#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x1,x2,x3,y1,y2,y3,d;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>d;
    if(sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3))<=d)
        cout<<"Yes";
    else if(sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))<=d)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
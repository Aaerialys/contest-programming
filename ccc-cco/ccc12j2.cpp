#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b&&b>c&&c>d)
        cout<<"Fish Diving";
    else if(a<b&&b<c&&c<d)
        cout<<"Fish Rising";
    else if(a==b&&b==c&&c==d)
        cout<<"Fish At Constant Depth";
    else
        cout<<"No Fish";
    return 0;
}
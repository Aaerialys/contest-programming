#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a[3],b[3],c[3],t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>c[2];
    if(a[0]==b[1])
        t+=max(0,c[1]);
    if(a[1]==b[2])
        t+=max(0,c[2]);
    if(a[2]==b[0])
        t+=max(0,c[0]);
    cout<<t;
    return 0;
}
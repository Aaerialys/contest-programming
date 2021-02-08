#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b+c!=180)
        cout<<"Error";
    else if(a==b&&b==c)
        cout<<"Equilateral";
    else if(a==b||b==c||c==a)
        cout<<"Isosceles";
    else
        cout<<"Scalene";
    return 0;
}
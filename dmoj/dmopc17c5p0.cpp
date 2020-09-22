#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int a,b;
char c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>c;
    if(c=='N'&&a>=b*5)
        cout<<"A";
    else if(c=='N'&&a>=b*2)
        cout<<"C";
    else if(c=='Y'&&a>=b*5)
        cout<<"B";
    else if(c=='Y'&&a>=b*2)
        cout<<"D";
    else
        cout<<"NO PIZZA";
    return 0;
}
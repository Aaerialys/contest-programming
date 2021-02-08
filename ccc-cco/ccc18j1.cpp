#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a,b,c,d;

int main()
{
    cin>>a>>b>>c>>d;
    if(b==c&&(a==9||a==8)&&(d==9||d==8))
        cout<<"ignore";
    else
        cout<<"answer";
    return 0;
}
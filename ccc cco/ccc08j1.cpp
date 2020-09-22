#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    double a,b;
    cin>>a>>b;
    a=a/b/b;
    if(a<18.5)
        cout<<"Underweight";
    else if(a>25)
        cout<<"Overweight";
    else
        cout<<"Normal weight";
    return 0;
}
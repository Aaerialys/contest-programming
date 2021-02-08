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
    b-=a;
    if(b<=0)
        cout<<"Congratulations, you are within the speed limit!";
    else if(b<=20)
        cout<<"You are speeding and your fine is $100.";
    else if(b<=30)
        cout<<"You are speeding and your fine is $270.";
    else
        cout<<"You are speeding and your fine is $500.";
    return 0;
}
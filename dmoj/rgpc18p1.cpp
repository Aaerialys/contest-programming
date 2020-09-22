#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a,b;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    if(a%b==0)
        cout<<"yes "<<a/b;
    else
        fori(b+1,a+1)
            if(a%i==0)
            {
                cout<<"no "<<i-b;
                return 0;
            }
    return 0;
}
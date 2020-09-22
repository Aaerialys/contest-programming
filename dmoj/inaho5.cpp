#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

unsigned long long t;
long long n,x;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        t+=-x;
    }
    if(t==0)
        cout<<0;
    else
        cout<<'-'<<t;
    return 0;
}
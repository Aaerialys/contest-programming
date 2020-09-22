#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    unsigned int n,t=0;
    cin>>n;
    while(n!=1)
    {
        t++;
        if(n%2==0)
            n/=2;
        else
            n=n*3+1;
    }
    cout<<t;
    return 0;
}
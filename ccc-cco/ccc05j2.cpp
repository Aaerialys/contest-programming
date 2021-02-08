#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int l,r,n,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>l>>r;
    fori(l,r+1)
    {
        n=0;
        forj(1,r+1)
            if(i%j==0)
                n++;
        if(n==4)
            t++;
    }
    cout<<"The number of RSA numbers between "<<l<<" and "<<r<<" is "<<t;
    return 0;
}
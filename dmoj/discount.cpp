#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,k,x,y,t=0;
    cin>>n>>k; k*=100;
    fori(0,n)
    {
        cin>>x>>y;
        if(x*(100-y)<=k)
            t++;
    }
    cout<<t;
    return 0;
}
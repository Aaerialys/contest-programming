#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

unsigned long long N,n,x=1,M=1LL<<32;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    fori(0,N)
    {
        cin>>n;
        x=1;
        forj(1,n+1)
        {
            x=x*j%M;
            if(x==0)
                break;
        }
        cout<<x<<"\n";
    }
    return 0;
}
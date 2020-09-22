#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,num[20][10],x,t;
bool carry;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>t;
        forj(0,10)
        {
            num[i][j]=t%10;
            t/=10;
        }
    }
    t=0;
    fori(1,1<<n)
    {
        carry=false;
        forj(0,10)
        {
            x=0;
            fork(0,n)
            {
                if(i&(1<<k))
                    x+=num[k][j];
            }
            if(x>=10)
                carry=true;
        }
        if(!carry)
            t=max(t,__builtin_popcountll(i));
    }
    cout<<t;
    return 0;
}
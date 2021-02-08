#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int r,l,a;
    cin>>r>>l;
    int light[r];
    int dp[100];
    fori(0,r)
    {
        light[r-i-1]=0;
        forj(0,l)
        {
            cin>>a;
            light[r-i-1]*=2;
            light[r-i-1]+=a;
        }
    }
    dp[0]=light[0];
    fori(1,r)
    {
        dp[i]=dp[i-1]^light[i];
    }
    a=0;
    fori(0,r)
    {
        bool x=true;
        forj(0,i)
        {
            if(dp[j]==dp[i])
                x=false;
        }
        if(x)
        {
            a++;
        }
    }
    cout<<a;
    return 0;
}
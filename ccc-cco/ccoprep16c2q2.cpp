#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;
int numb;
int dp[32];
int n,m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        m=0;
        cin>>numb;
        forj(0,32)
        {
            if(numb&(1<<j))
            {
                m=max(m,dp[j]+1);
            }
        }
        forj(0,32)
        {
            if(numb&(1<<j))
            {
                dp[j]=m;
            }
        }
    }
    m=0;
    fori(0,32)
        if(dp[i]>m)
            m=dp[i];
    cout<<m;
    return 0;
}
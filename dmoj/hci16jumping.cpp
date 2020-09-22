#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=2002;
int r,c,last;
long long dp[N][N],x,M=LLONG_MAX/4;
bool rock[N][N];
char ch;
long long sq(int x)
{
    return x*x;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>r;
    fori(0,r)
        forj(0,c)
        {
            cin>>ch;
            rock[j][i]=ch-'0';
            dp[j][i]=M;
        }
    fori(0,r)
        if(rock[0][i])
        {
            dp[0][i]=0;
        }
    fori(1,c)
    {
        last=0;
        forj(0,r)
            if(rock[i][j])
            {
                fork(last,j)
                {
                    if(rock[i-1][k]&&dp[i-1][k]+sq(k-j)<dp[i][j])
                    {
                        dp[i][j]=dp[i-1][k]+sq(k-j);
                        last=k;
                    }
                }
            }
        last=r-1;
        for(int j=r-1;j>=0;j--)
            if(rock[i][j])
                for(int k=last;k>=j;k--)
                {
                    if(rock[i-1][k]&&dp[i-1][k]+sq(k-j)<dp[i][j])
                    {
                        dp[i][j]=dp[i-1][k]+sq(k-j);
                        last=k;
                    }
                }

    }
    x=M;
    fori(0,r)
        x=min(x,dp[c-1][i]);
    cout<<x;
    return 0;
}
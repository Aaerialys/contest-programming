#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    n-=m;
    int ways[m+1][n+1];
    for(int i=0;i<=n;i++)
    {
        ways[0][i]=0;
    }
    for(int i=0;i<=m;i++)
    {
        ways[i][0]=1;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ways[i][j]=0;
            for(int k=0;k*(m-i+1)<=j;k++)
            {
                ways[i][j]+=ways[i-1][j-k*(m-i+1)];
            }
        }
    }
    cout<<ways[m][n]<<endl;
    return 0;
}
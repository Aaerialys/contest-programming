#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=1501;
int n,d[N][N],dp[N][N],m=INT_MAX;

int f(int x,int y)
{
    if(x>y)
        swap(x,y);
    if(dp[x][y]<INT_MAX/2)
        return dp[x][y];
    if(x!=y-1)
        return dp[x][y]=f(x,y-1)+d[y-1][y];
    fori(0,x)
        dp[x][y]=min(dp[x][y],f(x,i)+d[i][y]);
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,N)
        forj(0,N)
            dp[i][j]=INT_MAX/2;
    cin>>n;
    fori(0,n)
        forj(0,n)
            cin>>d[i][j];
    dp[0][1]=d[0][1];
    fori(0,n)
        m=min(m,f(i,n-1));
    cout<<m;
    return 0;
}
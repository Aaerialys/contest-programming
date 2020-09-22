#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int dp[20][300000];
int V,E,x,a,b,c;
int gr[20][20];

int path(int v,int mask)
{
    if(dp[v][mask]>=0)
        return dp[v][mask];
    if(v==V-1)
        return dp[v][mask]=0;
    fori(0,V)
    {
        if((~mask)&(1<<i)&&gr[v][i]>0)
        {
            dp[v][mask]=max(dp[v][mask],path(i,mask|(1<<i))+gr[v][i]);
        }
    }
    return dp[v][mask];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E;
    fori(0,20)
    {
        forj(0,20)
            gr[i][j]=-10000000;
    }
    fori(0,20)
        forj(0,300000)
            dp[i][j]=INT_MIN;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        gr[a][b]=c;
    }
    cout<<path(0,1)<<endl;
    return 0;
}
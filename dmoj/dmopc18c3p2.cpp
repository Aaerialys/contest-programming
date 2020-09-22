#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,a,b,mark[100001],best[100001][3],ee;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>mark[i];
    }
    fori(0,n)
    {
        cin>>a;
        mark[i]-=a;
        ee+=a;
    }
    fori(0,n)
    {
        best[i+1][0]=best[i][2];
        best[i+1][1]=max(best[i+1][0],best[i][0]+mark[i]);
        best[i+1][2]=max(best[i+1][1],best[i][1]+mark[i]);
    }
    cout<<best[n][2]+ee<<endl;
    return 0;
}
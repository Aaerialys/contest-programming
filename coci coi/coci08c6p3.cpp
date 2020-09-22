#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int cube[101][101];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b,t=0;
    cin>>n>>m;
    fori(0,m)
    {
        cin>>a>>b;
        cube[a][b]=1;
    }
    fori(0,n+1)
        forj(1,n+1)
            cube[i][j]+=cube[i][j-1];
    fori(0,n+1)
        forj(1,n+1)
            cube[j][i]+=cube[j-1][i];
    fori(1,sqrt(m)+1)
    {
        if(m%i==0)
        {
            a=m/i;
            forj(i,n+1)
            {
                fork(a,n+1)
                {
                    t=max(t,cube[j][k]-cube[j][k-a]-cube[j-i][k]+cube[j-i][k-a]);
                }
            }
            forj(i,n+1)
            {
                fork(a,n+1)
                {
                    t=max(t,cube[k][j]-cube[k][j-a]-cube[k-i][j]+cube[k-i][j-a]);
                }
            }
        }
    }
    cout<<m-t;
    return 0;
}
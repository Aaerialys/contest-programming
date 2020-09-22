#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=100010,M=1e4,L=8100;
int m,mx[10],my[10],n,nx[N],ny[N],d,x,y,f[M+10][M+10];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>m;
    fori(0,m)
        cin>>mx[i]>>my[i];
    cin>>n;
    fori(0,n)
    {
        cin>>nx[i]>>ny[i]; d=INT_MAX;
        forj(0,m)
            d=min(d,abs(mx[j]-nx[i])+abs(my[j]-ny[i]));
        d--;
        x=nx[i]+ny[i]; y=nx[i]-ny[i]+L/2;
        f[max(0,x-d)][max(0,y-d)]++;
        f[max(0,x-d)][min(M,y+d+1)]--;
        f[min(M,x+d+1)][max(0,y-d)]--;
        f[min(M,x+d+1)][min(M,y+d+1)]++;
    }
    m=0;
    fori(0,M)
        forj(1,M)
            f[i][j]+=f[i][j-1];
    fori(1,M)
        forj(0,M)
            f[i][j]+=f[i-1][j];
    fori(0,M)
        forj(0,M)
            m=max(m,f[i][j]);
    cout<<m;
    return 0;
}
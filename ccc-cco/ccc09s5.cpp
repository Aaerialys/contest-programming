#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,m,k,f[1010][30010],a,b,c,d,x,y,z;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n>>k;
    fori(0,k)
    {
        cin>>a>>b>>c>>d;
        x=max(a-c,1); y=min(a+c,n);
        forj(x,y+1)
        {
            z=floor(sqrt(1.0*(c*c-(j-a)*(j-a))));
            f[j][max(1,b-z)]+=d;
            f[j][min(m+1,b+z+1)]-=d;
        }
    }
    x=y=0;
    fori(0,n+1)
        forj(1,m+1)
        {
            f[i][j]+=f[i][j-1];
            if(x==f[i][j])
                y++;
            if(x<f[i][j])
            {
                x=f[i][j];
                y=1;
            }
        }
    cout<<x<<"\n"<<y;
    return 0;
}
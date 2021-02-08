#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,ans,x,t,o[100][15],vote[16];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>x; x--;
    fori(0,n)
        forj(0,m)
        {
            cin>>o[i][j];
            o[i][j]--;
        }
    fori(0,1<<m)
    {
        forj(0,m)
            vote[j]=0;
        forj(0,n)
            fork(0,m)
            {
                if(i&(1<<o[j][k]))
                {
                    vote[o[j][k]]++;
                    break;
                }
            }
        t=15;
        forj(0,m)
            if(vote[j]>vote[t])
                t=j;
        if(t==x)
        {
            ans=max(ans,__builtin_popcount(i));
        }
        if(i==(1<<m)-1)
            cout<<t+1<<endl;
    }
    cout<<m-ans<<endl;
    return 0;
}
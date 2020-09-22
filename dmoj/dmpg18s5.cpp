#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=200100,M=450;
int n,Q,x,y,p,q,r,b,bv[M][N],arr[N];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>Q;
    fori(0,n)
    {
        cin>>x; arr[i]=x;
        b=i/M;
        forj(1,sqrt(x))
            if(x%j==0)
            {
                bv[b][j]++;
                bv[b][x/j]++;
            }
        if(sqrt(x)==ceil(sqrt(x)))
            bv[b][(int)sqrt(x)]++;
    }
    fori(0,Q)
    {
        cin>>y;
        if(y==1)
        {
            cin>>p>>q>>r; p--; q--; x=0;
            if(p/M==q/M)
            {
                forj(p,q+1)
                    if(arr[j]%r==0)
                        x++;
            }
            else
            {
                int j;
                for(j=p;j%M!=0;j++)
                    if(arr[j]%r==0)
                        x++;
                for(j=j/M;(j+1)*M<=q;j++)
                    x+=bv[j][r];
                forj(q-q%M,q+1)
                    if(arr[j]%r==0)
                        x++;
            }
            cout<<x<<"\n";
        }
        if(y==2)
        {
            cin>>p>>q; p--; b=p/M;
            x=q;
            forj(1,sqrt(x))
                if(x%j==0)
                {
                    bv[b][j]++;
                    bv[b][x/j]++;
                }
            if(sqrt(x)==ceil(sqrt(x)))
                bv[b][(int)sqrt(x)]++;
            x=arr[p];
            forj(1,sqrt(x))
                if(x%j==0)
                {
                    bv[b][j]--;
                    bv[b][x/j]--;
                }
            if(sqrt(x)==ceil(sqrt(x)))
                bv[b][(int)sqrt(x)]--;
            arr[p]=q;
        }
    }
    return 0;
}
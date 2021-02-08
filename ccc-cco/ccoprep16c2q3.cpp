#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=200400,B=200,R=1000;
int btran[N],bnx[N],nx[N],n,q,f,x,a,b,t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        nx[i]=min(i+x,n);
    }
    bnx[n]=n;
    for(int i=n-1;i>=0;i--)
    {
        btran[i]=btran[nx[i]]+1;
        bnx[i]=bnx[nx[i]];
        if(nx[i]/B!=i/B)
        {
            btran[i]=1;
            bnx[i]=nx[i];
        }
    }
    cin>>q;
    fori(0,q)
    {
        cin>>f;
        if(f==1)
        {
            cin>>a;
            t=0;
            while(a<n)
            {
                t+=btran[a];
                a=bnx[a];
            }
            cout<<t<<"\n";
        }
        if(f==2)
        {
            cin>>a>>b;
            nx[a]=a+b;
            for(int j=a;j/B==a/B&&j>=0;j--)
            {
                btran[j]=btran[nx[j]]+1;
                bnx[j]=bnx[nx[j]];
                if(nx[j]/B!=j/B)
                {
                    btran[j]=1;
                    bnx[j]=nx[j];
                }
            }
        }
    }
    return 0;
}
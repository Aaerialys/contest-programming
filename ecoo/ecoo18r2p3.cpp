#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long m,k,a,b,p,q,t,tt;
    forj(0,10)
    {
        cin>>m>>k;
        tt=0;
        fori(2,m+1)
        {
            if(m%i==0)
            {
                q=0;
                while(m%i==0)
                {
                    p=i;
                    m/=i;
                    q++;
                }
                q*=k; a=1; b=p; t=0;
                while(a<q)
                {
                    a=a*p+1;
                    b*=p;
                }
                while(q>0)
                {
                    t+=q/a*b;
                    q=q%a;
                    a=(a-1)/p;
                    b/=p;
                }
                tt=max(tt,t);
            }
        }
        cout<<tt<<endl;
    }
    return 0;
}
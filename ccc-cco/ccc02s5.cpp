#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int h,w,t,p,q;
double m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>w>>h>>p>>q; t=INT_MAX;
    if(p==w||q==0)
    {
        cout<<0;
        return 0;
    }
    m=q*1.0/(w-p);
    fori(1,1e5)
        if(abs(m*(i*w-p)-round(m*(i*w-p)/h)*h)<5)
        {
            t=i-2+ceil(m*(i*w-p)/h);
            break;
        }
    fori(1,1e3)
        if(abs((i*h/m+p)-round((i*h/m+p)/w)*w)<5)
        {
            t=min(t,i-2+(int)ceil((i*h/m+p)/w));
            break;
        }
    if(t==INT_MAX)
        cout<<0;
    else
        cout<<t;
    return 0;
}
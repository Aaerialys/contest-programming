#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    double s,b,m=1e100;
    cin>>n;
    int sour[n],bitter[n];
    fori(0,n)
    {
        cin>>sour[i]>>bitter[i];
    }
    fori(1,1<<n)
    {
        s=1;
        b=0;
        forj(0,n)
        {
            if(i&1<<j)
            {
                s*=sour[j];
                b+=bitter[j];
            }
        }
        m=min(m,abs(s-b));
    }
    cout<<round(m);
    return 0;
}
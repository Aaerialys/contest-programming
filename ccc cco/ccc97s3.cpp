#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,m,o,x,t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    fori(0,t)
    {
        cin>>n; m=x=o=0;
        while(n+m>1)
        {
            cout<<"Round "<<x<<": "<<n<<" undefeated, "<<m<<" one-loss, "<<o<<" eliminated\n";
            x++;
            if(m==1&&n==1)
            {
                m=2;
                n=0;
            }
            else
            {
                o+=m/2;
                m=(m+1)/2;
                m+=n/2;
                n=(n+1)/2;
            }
        }
        cout<<"Round "<<x<<": "<<n<<" undefeated, "<<m<<" one-loss, "<<o<<" eliminated\n";
        cout<<"There are "<<x<<" rounds.\n\n";
    }
    return 0;
}
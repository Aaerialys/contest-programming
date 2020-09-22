#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long t,digit[159],d,n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    digit[0]=digit[2]=digit[3]=1;
    fori(4,150)
        digit[i]=digit[i-2]+digit[i-3];
    cin>>t;
    fork(0,t)
    {
        cin>>n; d=1;
        while(n>digit[d])
        {
            n-=digit[d];
            d++;
        }
        while(d>0)
        {
            if(d>=3&&digit[d-3]>=n)
            {
                d-=3;
                cout<<420;
            }
            else if(d>=2)
            {
                n-=digit[d-3];
                d-=2;
                cout<<69;
            }
        }
        cout<<"\n";
    }
    return 0;
}
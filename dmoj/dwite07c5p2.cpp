#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int x,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,5)
    {
        cin>>x; t=0;
        fori(2,x+1)
            while(x%i==0)
            {
                x/=i;
                t++;
            }
        if(t==1)
            cout<<"0\n";
        else
            cout<<t<<"\n";
    }
    return 0;
}
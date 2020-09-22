#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long n,x,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        if(x<=2)
            continue;
        forj(2,sqrt(x)+1)
            if(x%j==0)
            {
                t++;
                break;
            }
    }
    cout<<t;
    return 0;
}
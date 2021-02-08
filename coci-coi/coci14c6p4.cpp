#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,k,x;
    cin>>n>>k;
    if(k<2)
    {
        cout<<-1;
        return 0;
    }
    x=k;
    while(x<=n)
    {
        fori(0,k)
        {
            cout<<x<<" ";
            x--;
        }
        x+=k<<1;
    }
    fori(0,k)
    {
        if(x<=n)
            cout<<x<<" ";
        x--;
    }
    return 0;
}
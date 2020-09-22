#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int coin[10],n,t,s;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    fori(0,n)
        cin>>coin[i];
    fori(0,n)
    {
        t+=s/coin[n-i-1];
        s%=coin[n-i-1];
    }
    if(s>0)
        cout<<-1;
    else
        cout<<t;
    return 0;
}
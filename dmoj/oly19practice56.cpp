#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int t,n,u,f,d;
char ch;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>t>>n>>u>>f>>d;
    fori(0,n)
    {
        cin>>ch;
        if(ch=='f')
            t-=f*2;
        else
            t-=u+d;
        if(t<0)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,t=0,h=0;
    cin>>n>>m; m++;
    fori(0,n)
    {
        cin>>x;
        x%=m; h^=x;
    }
    if(h==0)
        cout<<"don't play";
    else
        cout<<"play";
    return 0;
}
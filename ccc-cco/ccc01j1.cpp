#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n/2)
    {
        forj(0,i*2+1)
            cout<<'*';
        forj(0,n*2-(i*2+1)*2)
            cout<<" ";
        forj(0,i*2+1)
            cout<<'*';
        cout<<endl;
    }
    fori(0,n*2)
        cout<<'*';
    cout<<endl;
    ford(i,n/2-1,0)
    {
        forj(0,i*2+1)
            cout<<'*';
        forj(0,n*2-(i*2+1)*2)
            cout<<" ";
        forj(0,i*2+1)
            cout<<'*';
        cout<<endl;
    }
    return 0;
}
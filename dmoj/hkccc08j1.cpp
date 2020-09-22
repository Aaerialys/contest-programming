#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,a,b,m1,m2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>a>>b;
        m1=max(m1,a*b);
    }
    cin>>n;
    fori(0,n)
    {
        cin>>a>>b;
        m2=max(m2,a*b);
    }
    if(m1<m2)
        cout<<"Natalie";
    if(m1==m2)
        cout<<"Tie";
    if(m1>m2)
        cout<<"Casper";
    return 0;
}
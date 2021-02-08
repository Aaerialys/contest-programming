#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a==0)
    {
        cout<<0;
        return 0;
    }
    if(a>b)
        cout<<a/b<<" ";
    a=a%b;
    if(a==0) return 0;
    fori(2,min(a,b)+1)
        while(a%i==0&&b%i==0)
        {
            a/=i;
            b/=i;
        }
    cout<<a<<"/"<<b;
    return 0;
}
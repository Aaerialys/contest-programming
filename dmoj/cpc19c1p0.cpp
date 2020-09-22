#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int a[2],b[2],x,y;
char ch;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(1,5)
    {
        cin>>ch;
        if(ch=='R')
        {
            a[x++]=i;
        }
        if(ch=='L')
        {
            b[y++]=i;
        }
    }
    cout<<b[0]<<" "<<a[0]<<"\n"<<b[1]<<" "<<a[1]<<"\n";
    return 0;
}
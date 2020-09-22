#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

unsigned long long x,y,a,b;

void egcd(unsigned long long a,unsigned long long b)
{
    if(b==0)
    {
        x=1; y=0;
        return;
    }
    egcd(b,a%b);
    x-=a/b*y-y;
    y=x-y;
    x-=y;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    egcd(a,b);
    cout<<(x+b)%b;
    return 0;
}
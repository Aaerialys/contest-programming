#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,x,y=1;
    cin>>n>>x;
    fori(1,n)
    {
        cin>>y;
        x=gcd(x,y);
    }
    y=1;
    fori(2,sqrt(x)+1)
    {
        if(x%i==0)
        {
            while(x%i==0&&i<sqrt(x)+1)
                x/=i;
            y=i;
        }
    }
    y=max(x,y);
    if(y==1)
        cout<<"DNE";
    else
        cout<<y;
    return 0;
}
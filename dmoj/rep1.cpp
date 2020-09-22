#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
long long n,k,t;

long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("out3.txt", "w", stdout);
    cin>>t;
    cout<<t<<endl;
    fori(0,t)
    {
        cin>>n>>k;
        cout<<n/gcd(n,k)<<endl;
    }
    return 0;
}
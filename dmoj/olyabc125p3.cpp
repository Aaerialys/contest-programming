#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int n,num[100100],pre[100100],pos[100100],m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>num[i];
    pre[0]=num[0]; pos[n-1]=num[n-1];
    fori(1,n)
        pre[i]=gcd(pre[i-1],num[i]);
    ford(i,n-2,0)
        pos[i]=gcd(pos[i+1],num[i]);
    m=max(pre[n-2],pos[1]);
    fori(2,n)
        m=max(m,gcd(pre[i-2],pos[i]));
    cout<<m;
    return 0;
}
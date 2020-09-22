#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    int numb[n];
    fori(0,n)
    {
        cin>>numb[i];
    }
    sort(numb,numb+n);
    fori(0,n-1)
    {
        numb[i]=numb[i+1]-numb[i];
    }
    x=numb[0];
    fori(1,n-1)
    {
        x=gcd(x,numb[i]);
    }
    cout<<x;
    fori(2,sqrt(x))
    {
        if(x%i==0)
            cout<<" "<<i<<" "<<x/i;
    }
    if(round(sqrt(x))==sqrt(x))
        cout<<" "<<sqrt(x);
    cout<<endl;
    return 0;
}
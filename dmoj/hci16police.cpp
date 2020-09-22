#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,h,numb[100001],mi[100001],w;

long long sqr(int x)
{
    return x*x;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>h;
    fori(0,n)
        cin>>numb[i];
    mi[0]=h;
    fori(1,n)
    {
        mi[i]=INT_MAX;
        forj(w,i+1)
        {
            if(mi[i]>=(numb[i]-numb[j])*(numb[i]-numb[j])+mi[j-1]+h)
            {
                w=j;
                mi[i]=(numb[i]-numb[j])*(numb[i]-numb[j])+mi[j-1]+h;
            }
        }
    }
    cout<<mi[n-1];
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,m,x,k,cute[200100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    fori(1,n+1)
        cin>>cute[i];
    fori(1,n+1)
        cute[i]+=cute[i-1];
    fori(1,n+1)
    {
        while(cute[i]-cute[x]>=k)
            x++;
        m=max(m,i-x);
    }
    cout<<m;
    return 0;
}
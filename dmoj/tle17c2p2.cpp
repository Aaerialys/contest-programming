#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;


int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int k,n,x,u[500001];
    cin>>k;
    fori(0,k)
        cin>>u[i];
    sort(u,u+k);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        cout<<x-(upper_bound(u,u+k,x)-u)<<"\n";
    }
    return 0;
}
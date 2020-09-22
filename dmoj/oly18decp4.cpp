#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int n,m,numb[100001];
long long t=0;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fori(0,n)
        cin>>numb[i];
    sort(numb,numb+n);
    fori(0,n)
    {
        t+=upper_bound(numb,numb+i,m-numb[i])-numb;
    }
    cout<<t;
    return 0;
}
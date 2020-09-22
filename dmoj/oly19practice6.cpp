#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=100100;
int n,arr[N],mii[N];
long long t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>arr[i];
    ford(i,n-1,0)
        mii[i]=max(arr[i]+1,mii[i+1]-1);
    fori(1,n)
        mii[i]=max(mii[i],mii[i-1]);
    fori(0,n)
        t+=mii[i]-arr[i]-1;
    cout<<t<<endl;
    return 0;
}
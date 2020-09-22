#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
int n,a[1000000];

bool cmp(int a,int b)
{
    if(a%10==b%10)
        return a>b;
    return a%10<b%10;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>a[i];
    sort(a,a+n,cmp);
    fori(0,n)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
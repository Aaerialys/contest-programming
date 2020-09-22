#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,t,a[100],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in7.txt", "r", stdin);
    //freopen("out7.txt", "w", stdout);
    cin>>n; assert(1<=n&&n<=10);
    fori(0,n)
    {
        cin>>a[i];  assert(1<=a[i]&&a[i]<=10);
        t+=a[i];
    }
    fori(0,n)
        if(a[i]!=t/n)
            ans++;
    cout<<ans;
    return 0;
}
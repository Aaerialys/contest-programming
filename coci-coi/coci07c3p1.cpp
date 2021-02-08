#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int a[3];
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[1]*2==a[2]+a[0])
        cout<<a[2]*2-a[1];
    else if(a[1]*2<a[2]+a[0])
        cout<<(a[1]+a[2])/2;
    else if(a[1]*2>a[2]+a[0])
        cout<<(a[0]+a[1])/2;
    return 0;
}
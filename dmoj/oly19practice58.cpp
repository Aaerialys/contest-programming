#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(ll i=a;i<b;i++)
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

ll n,m,t,x;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n; m=(sqrt(8*n+1)-1)/2;
    fori(1,m+2)
    {
        x=i*(i+1)/2;
        if(n-x>=0&&(n-x)%i==0)
            t++;
    }
    cout<<t;
    return 0;
}
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

const int N=1000100;
ll n,x,t,a[N],mx,my,s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>x; mx=max(mx,x);
        a[x]++;
        s[x]+=x;
    }
    fori(1,N)
    {
        s[i]+=s[i-1];
        a[i]+=a[i-1];
    }
    fori(0,n)
    {
        cin>>x; my=max(my,x);
        t+=s[x]+(a[N-1]-a[x])*x;
    }
    if(mx!=my)
        cout<<-1;
    else
        cout<<t;
    return 0;
}
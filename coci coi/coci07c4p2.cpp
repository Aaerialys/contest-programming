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

int N,n,d[10],x,y,t=inf;
set<int> di;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n; N=n;
    for(;n>0;n/=10)
        d[x++]=n%10;
    sort(d,d+x);
    do
    {
        y=0;
        fori(0,x)
            y=y*10+d[i];
        if(y>N)
            t=min(t,y);
    } while((next_permutation(d,d+x)));
    if(t==inf)
        cout<<0;
    else
        cout<<t;
    return 0;
}
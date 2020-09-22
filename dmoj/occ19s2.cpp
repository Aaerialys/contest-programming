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

ll n;
int t,d[19];

int go(int x,bool lim)
{
    if(x==19)
        return 1;
    if(d[x]>3||lim==0)
        return go(x+1,0)*2;
    if(d[x]==3)
        return go(x+1,0)+go(x+1,1);
    if(d[x]==2)
        return go(x+1,1);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    ford(i,18,0)
    {
        d[i]=n%10;
        n/=10;
    }
    fori(0,19)
    {
        n=n*10+d[i];
        if(n<10)
            t+=go(i,1);
        else
            t+=go(i,0);
    }
    cout<<t;
    return 0;
}
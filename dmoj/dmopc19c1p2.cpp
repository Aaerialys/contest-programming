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

string f0="Good writing is good writing is good writing.",p="Good writing is good ",pp=" writing is good ",ppp=" is good writing.";
ll sz[31],q,N,K;
char ans(int n,int k)
{
    if(k>=sz[n])
        return '.';
    if(n==0)
        return f0[k];
    if(k<21)
        return p[k];
    k-=21;
    if(k<sz[n-1])
        return ans(n-1,k);
    k-=sz[n-1];
    if(k<17)
        return pp[k];
    k-=17;
    if(k<sz[n-1])
        return ans(n-1,k);
    k-=sz[n-1];
    if(k<17)
        return ppp[k];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    sz[0]=45;
    fori(1,31)
        sz[i]=sz[i-1]*2+21+17+17;
    cin>>q;
    fori(0,q)
    {
        cin>>N>>K;
        cout<<ans(N,K-1)<<"\n";
    }
    return 0;
}
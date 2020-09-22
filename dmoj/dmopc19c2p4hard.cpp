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

const int N=2001,M=1e9+7;
ll n,t,q,val[N],way[N],a,b,c,ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>t>>q; way[0]=1;
    fori(0,n)
    {
        cin>>val[i];
        ford(j,N-1,val[i])
            way[j]=(way[j]+way[j-val[i]])%M;
    }
    fori(0,q)
    {
        cin>>a>>b>>c;  a--; b--; c-=val[a]+val[b]; t=0;
        fori(0,c+1)
            ans[i]=way[i];
        fori(val[a],c+1)
            ans[i]=(ans[i]-ans[i-val[a]]+M)%M;
        fori(val[b],c+1)
            ans[i]=(ans[i]-ans[i-val[b]]+M)%M;
        fori(0,c+1)
            t+=ans[i];
        cout<<t%M<<"\n";

    }
    return 0;
}
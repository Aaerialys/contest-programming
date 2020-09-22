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

const int N=1000010,M=1e9+7,B=26;
ll n,snum[N],p[N],dp[N];
string in;
int x,y,t=1;

ll num(int l,int r)
{
    return (snum[r]-snum[l-1]*p[r-l+1]%M+M)%M;
}
ll go(int l,int r)
{
    if(dp[l]!=-1)
        return dp[l];
    if(l>r)
        return dp[l]=0;
    dp[l]=1;
    fori(0,(r-l+1)/2)
    {
        x=num(l,l+i); y=num(r-i,r);
        if(num(l,l+i)==num(r-i,r))
            return dp[l]=go(l+i+1,r-i-1)+2;
    }
    return dp[l];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    p[0]=1;
    fori(1,N)
        p[i]=p[i-1]*B%M;
    cin>>n;
    forj(0,n)
    {
        seto(dp,-1);
        cin>>in;
        in="."+in;
        fori(1,in.size())
            snum[i]=(snum[i-1]*B%M+in[i]-'a'+1)%M;
        cout<<go(1,in.size()-1)<<"\n";
    }
    return 0;
}
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

const ll N=2010,M=1e9+7;
ll fpow(ll a,ll b)
{
    if(b==0)
        return 1;
    ll t=fpow(a,b/2);
    if(b&1)
        return t*t%M*a%M;
    return t*t%M;
}
ll n,x,y,d[2][N],s[2][N],co[N],fact[N],MM=M*M;
bool eo=true;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    s[0][0]=fact[0]=1;
    fori(1,N)
        fact[i]=fact[i-1]*i%M;
    cin>>n;
    fori(0,n+1)
    {
        cout<<"? "<<i<<endl;
        cin>>d[0][i];
    }
    fori(0,n+1)
    {
        eo=!eo;
        if(i>0)
        {
            s[eo][0]=0;
            forj(1,i+1)
                s[eo][j]=((1-i)*s[!eo][j]+s[!eo][j-1]+MM)%M;
            forj(i,n+1)
                d[eo][j]=(d[!eo][j]-d[!eo][j-1]+MM)%M;
        }
        x=fpow(fact[i],M-2)*d[eo][i]%M;
        forj(0,i+1)
            co[j]=(co[j]+s[eo][j]*x+MM)%M;
    }
    cout<<"! ";
    ford(i,n,0)
        cout<<co[i]<<" ";
    //freopen("", "r", stdin);
    return 0;
}
/**

f\left(x\right)=\sum_{k=0}^{n}\frac{d_{k}}{k!}\frac{x!}{\left(x-k\right)!}
3 1 4 29 106
*/
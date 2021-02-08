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
typedef pair<int,short> pii;

const int N=100010;
ll n,m,K,x[101],y[101],r[101],a,b,c,t;
vector<pii> pp;
multiset<int> mx;
int l;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("nlo.in.1", "r", stdin);
    cin>>n>>m>>K;
    fori(0,K)
    {
        cin>>x[i]>>y[i]>>r[i];
        x[i]--; y[i]--;
    }
    fori(0,n)
    {
        pp.clear();
        forj(0,K)
        {
            if(i>=max(0LL,x[j]-r[j])&&i<min(n,x[j]+r[j]+1))
            {
                a=sqrt(r[j]*r[j]-(i-x[j])*(i-x[j]));
                pp.push_back({max(0LL,y[j]-a),K-j});
                pp.push_back({min(m,y[j]+a+1),j-K});
            }
        }
        sort(pp.begin(),pp.end());
        l=0; mx.clear(); mx.insert(K); pp.push_back({m,-K-1});
        for(auto j:pp)
        {
            t+=(0LL+j.pf-l)*(*mx.begin());
            if(j.ps>0)
                mx.insert(j.ps-1);
            if(j.ps<0)
                mx.erase(mx.find(-j.ps-1));
            l=j.pf;
        }
    }
    cout<<t;
    return 0;
}
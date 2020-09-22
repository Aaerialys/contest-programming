#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i--)
#define ford(i,a,b) for(__typeof(a) i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define pow2(x) (1LL<<(x))
using namespace std;
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#endif
typedef long long ll; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
mt19937 randgen(time(0)); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=2010,L=11,Q=800001;
ll n,q,A[N],B[N],C[N],K,X,a,b,t,st[L][N],ans[Q];
vector<pii> que[N];
vector<pair<double,ll>> sect;
double d,EPS=1e-6;
ll maxx(int l,int r)
{
    int z=31-__builtin_clz(r-l+1); //!63-__builtin_clzll(r-l+1) for long long
    return max(st[z][l],st[z][r-(1<<z)+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("solar-1c.in", "r", stdin); //freopen("", "w", stdout);
    cin>>X>>K>>n>>q;
    fori(0,n)
        cin>>A[i]>>B[i]>>C[i];
    fori(0,q)
    {
        cin>>a>>b;
        que[a-1].pb({b,i});
    }
    fori(0,N)
    {
        sect.clear(); sect.pb({0,0});
        forj(0,n)
        {

            if(j==i)
                continue;
            if(A[j]>A[i])
                sect[0].ps+=C[j];
            if(A[j]<A[i]&&B[j]>B[i])
            {
                d=1.0*(A[j]-A[i])*X/(A[j]-A[i]-B[j]+B[i]);
                if(d<X)
                    sect.pb({d,C[j]});
            }
            if(A[j]>A[i]&&B[j]<B[i])
            {
                d=1.0*(A[j]-A[i])*X/(A[j]-A[i]-B[j]+B[i]);
                if(d<X)
                    sect.pb({d,-C[j]});
            }
        }
        sort(sect.begin(),sect.end()); a=sect.size();
        forj(1,a)
            if(abs(sect[j-1].pf-sect[j].pf)<EPS)
            {
                sect[j].ps+=sect[j-1].ps;
                sect[j-1]=sect[0];
            }
        sort(sect.begin(),sect.end()); sect.resize(unique(sect.begin(),sect.end())-sect.begin()); a=sect.size();
        forj(1,a)
            sect[j].ps+=sect[j-1].ps;
        forj(0,a)
            st[0][j]=sect[j].ps;
        forj(1,L)
            fork(0,a-pow2(j)+1)
                st[j][k]=max(st[j-1][k],st[j-1][k+pow2(j-1)]);
        forj(0,que[i].size())
            ans[que[i][j].ps]=maxx(upper_bound(sect.begin(),sect.end(),(pair<double,ll>){que[i][j].pf,INF})-sect.begin()-1,lower_bound(sect.begin(),sect.end(),(pair<double,ll>){que[i][j].pf+K,INF})-sect.begin()-1);
    }
    fori(0,q)
        cout<<ans[i]<<"\n";
    return 0;
}
/**

*/
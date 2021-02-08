#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a);i>=(b);i--)
#define fori(a,b) foru(i,a,b)
#define forj(a,b) foru(j,a,b)
#define fork(a,b) foru(k,a,b)
#define seto(x,i) memset(x,i,sizeof x)
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{ll operator()(ll x) const{x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};
#define nl "\n"

const int N=200010,M=MOD;
ll n,m,K,x,y,z,z2,l,id,r,o[N],mk,temp;
vector<ll> num[N];
pii lr[N];
priority_queue<tuple<ll,int,int,int,int>> nxt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("d2p3.4-01.in", "r", stdin); //freopen("", "w", stdout);
    cin>>m>>n>>K;
    fori(0,m){
        cin>>x>>y; num[x-1].pb(y);
    }
    fori(0,n) cin>>lr[i].pf>>lr[i].ps;
    y=0;
    fori(0,n){
        if(!lr[i].ps) num[i].clear();
        num[i].pb(INF); num[i].pb(0);
        sort(all(num[i]));
        forj(1,min(lr[i].pf+1,sz(num[i]))) y+=num[i][j];
        y=min(y,INF);
    }
    iota(o,o+n,0); sort(o,o+n,[&](int a,int b){return num[a][lr[a].pf+1]-num[a][lr[a].pf]<num[b][lr[b].pf+1]-num[b][lr[b].pf];});
    nxt.emplace(-y,0,lr[o[0]].pf-1,lr[o[0]].pf,inf);
    //cin.clear(); freopen("d2p3.4-01.out", "r", stdin);
    fori(0,K){
        tie(x,y,l,id,r)=nxt.top(); nxt.pop(); x=-x; z=o[y]; if(y<n) z2=o[y+1];
        if(x>1e15) break;
        //cin>>temp; if(temp!=x) cout<<i<<" "<<x<<" "<<temp<<endl;
        cout<<x<<nl;
        mk++; assert(id>=0); assert(x>=0);
        if(id+1<r) nxt.emplace(-(x+num[z][id+1]-num[z][id]),y,l,id+1,r),temp=(x+num[z][id+1]-num[z][id]);
        if(max(0,l)+1<id&&l>lr[z].pf-lr[z].ps) nxt.emplace(-(x+num[z][max(0,l)+1]-num[z][max(0,l)]),y,l-1,max(0,l)+1,id),temp=(x+num[z][max(0,l)+1]-num[z][max(0,l)]);
        if(y<n-1&&mk>1) nxt.emplace(-(x+num[z2][lr[z2].pf+1]-num[z2][lr[z2].pf]),y+1,lr[z2].pf-1,lr[z2].pf+1,inf),temp=(x+num[z2][lr[z2].pf+1]-num[z2][lr[z2].pf]);
        if(y<n-1&&id==lr[z].pf+1&&r==inf) nxt.emplace(-(x-num[z][id]+num[z][id-1]+num[z2][lr[z2].pf+1]-num[z2][lr[z2].pf]),y+1,lr[z2].pf-1,lr[z2].pf+1,inf),temp=(x-num[z][id]+num[z][id-1]+num[z2][lr[z2].pf+1]-num[z2][lr[z2].pf]);
    }
    fori(mk,K) cout<<-1<<nl;
    return 0;
}
/**
64 (0,1)
3 54 69 129 134 208 242 292 (0,6)
71 (0,0)
9 29 37 52 111 112 218 (0,6)
1 (0,1)
134 (0,0)
41 61 146 (0,3)

3 5 6
1 3

5 2 7
1 5
1 3
2 3
1 6
2 1
1 2
1 2



2 8
3 2 1 2
2 3 4

2 4
2 10 1
2 10 9
*/
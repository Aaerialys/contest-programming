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
struct chash{int operator()(ll x) const{x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};
#define nl "\n"

const int N=P2(19),M=MOD;
struct node{
    ll v,lz;
};
struct SegTree{
    node seg[2*N];
    void build(){seto(seg,0);}
    void pull(int x){seg[x].v=max(seg[2*x].v,seg[2*x+1].v);}
    void push(int x){
        if(!seg[x].lz) return;
        if(x<N) fori(0,2) seg[2*x+i].lz+=seg[x].lz;
        seg[x].v+=seg[x].lz; seg[x].lz=0;
    }
    void upd(int lo,int hi,ll v,int l=0,int r=N-1,int x=1){
        push(x);
        if(hi<l||r<lo) return;
        if(lo<=l&&r<=hi){
            seg[x].lz=v; push(x);
            return;
        }
        int mid=(l+r)/2;
        upd(lo,hi,v,l,mid,2*x); upd(lo,hi,v,mid+1,r,2*x+1);
        pull(x);
    }
    ll query(int lo,int hi,int l=0,int r=N-1,int x=1){
        push(x);
        if(hi<l||r<lo) return -INF;
        if(lo<=l&&r<=hi) return seg[x].v;
        int mid=(l+r)/2;
        return max(query(lo,hi,l,mid,2*x),query(lo,hi,mid+1,r,2*x+1));
    }
} st;
ll n,m,R,C,K,x,y,z,ans,pre,cur;
vector<int> poi;
gp_hash_table<int,int,chash> cord;
vector<tuple<int,int,int,ll>> e;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>R>>C>>n>>m>>K;
    assert(1<=R&&R<=n&&n<=1e9); assert(1<=C&&C<=m&&m<=1e9); assert(1<=K&&K<=1e5);
    fori(0,K){
        cin>>x>>y>>z;
        assert(1<=x&&x<=n); assert(1<=y&&y<=m); assert(-1e12<=z&&z<=1e12);
        poi.pb(y); poi.pb(max(1,y-C+1));
        e.eb(max(1,x-R+1),max(1,y-C+1),y,z); e.eb(x+1,max(1,y-C+1),y,-z);
    }
    poi.pb(1); poi.pb(m-C+1); ford(i,sz(poi)-1,0) poi.pb(poi[i]+1);
    sort(all(poi)); poi.erase(unique(all(poi)),poi.end()); fori(0,sz(poi)) cord[poi[i]]=i;
    e.eb(n+1,0,0,0); sort(all(e)); ans=-INF; pre=1; st.build();
    for(auto i:e){
        tie(cur,x,y,z)=i;
        if(pre>n-R+1) break;
        if(pre!=cur) ans=max(ans,st.query(cord[1],cord[m-C+1]));
        pre=cur;
        st.upd(cord[x],cord[y],z);
    }
    cout<<ans<<endl; cin.clear();
    return 0;
}
/**
3 3
5 5
5
3 3 1000
1 3 -9999
5 3 -9999
3 1 -9999
3 5 -9999
*/
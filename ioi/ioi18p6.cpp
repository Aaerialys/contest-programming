#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,fma,mmx,popcnt,tune=native" //#pragma GCC optimize "prefetch-loop-arrays"
using namespace std; using namespace __gnu_pbds;
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
#define em emplace
#define mp make_pair
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
    typedef int64_t i128; typedef uint64_t ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld; typedef string str;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<class T1,class T2> using ordered_map=tree<T1,T2,less<T1>,rb_tree_tag,tree_order_statistics_node_update>; template<class T1> using ordered_set=ordered_map<T1,null_type>;
template<class T> using minpq=std::priority_queue<T,vector<T>,greater<T>>; template<class T> using maxpq=std::priority_queue<T,vector<T>,less<T>>;
template<class T> using minpairingheap=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>; template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,less<T>,pairing_heap_tag>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
const ll SEED=443214^chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
template<class T1,class T2>constexpr const bool ckmin(T1&x,T2&y){return x>y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmin(T&x,Ts&...xs){return ckmin(x,_min(xs...));}
template<class T1,class T2>constexpr const bool ckmax(T1&x,T2&y){return x<y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmax(T&x,Ts&...xs){return ckmax(x,_max(xs...));}
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}};
void fileIn(string s){freopen(s.c_str(),"r",stdin);} void fileOut(string s){freopen(s.c_str(),"w",stdout);} void fileIO(string s){fileIn(s+".in"); fileOut(s+".out");}
string to_string(char c){return string(1,c);} string to_string(char* s){return (string)s;} string to_string(string s){return s;}
template<class T> string to_string(complex<T> c){stringstream ss; ss<<c; return ss.str();} template<class T1,class T2> string to_string(pair<T1,T2> p){return "("+to_string(p.pf)+","+to_string(p.ps)+")";}
template<size_t SZ> string to_string(bitset<SZ> b){string ret=""; fori(0,SZ) ret+=char('0'+b[i]); return ret;}
template<class T> string to_string(T v){string ret="{"; for(const auto& x:v) ret+=to_string(x)+","; return ret+"}";}
void DBG(){cerr<<"]"<<endl;} template<class T,class... Ts> void DBG(T x,Ts... xs){cerr<<to_string(x); if(sizeof...(xs)) cerr<<", "; DBG(xs...);}
#ifdef LOCAL_PROJECT
    #define dbg(...) cerr<<"Line("<< __LINE__<<") -> ["<<#__VA_ARGS__<<"]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
#define nl "\n"

const int N=P2(20),M=MOD,L=20;
struct LiChao{
    pll seg[2*N];
    ll lz[2*N];
    ll f(pll i,int x){
        return i.pf*x+i.ps;
    }
    void push(int x){
        if(!lz[x]) return;
        if(x<N) fori(0,2) lz[2*x+i]+=lz[x];
        seg[x].ps+=lz[x];
        lz[x]=0;
    }
    LiChao(){
        fori(1,2*N) seg[i]=mp(0,INF);
    }
    void upd(int lo,int hi,pll v,int l=0,int r=N-1,int x=1){
        push(x);
        if(r<lo||hi<l) return;
        int mid=l+r>>1;
        if(lo<=l&&r<=hi){
            if(f(seg[x],mid)>f(v,mid)) swap(seg[x],v);
            if(l==r) return;
            if(f(seg[x],l)>f(v,l)) upd(l,mid,v,l,mid,2*x);
            else if(f(seg[x],r)>f(v,r)) upd(mid+1,r,v,mid+1,r,2*x+1);
            return;
        }
        upd(lo,hi,v,l,mid,2*x); upd(lo,hi,v,mid+1,r,2*x+1);
    }
    void upd2(int lo,int hi,ll v,int l=0,int r=N-1,int x=1){
        push(x);
        if(r<lo||hi<l) return;
        if(lo<=l&&r<=hi){
            lz[x]+=v; push(x);
            return;
        }
        int mid=l+r>>1;
        upd2(lo,hi,v,l,mid,2*x); upd2(lo,hi,v,mid+1,r,2*x+1);
    }
    ll query(int X,int l=0,int r=N-1,int x=1){
        push(x);
        if(l==r) return f(seg[x],X);
        int mid=l+r>>1;
        if(X<=mid) return min(query(X,l,mid,2*x),f(seg[x],X));
        return min(query(X,mid+1,r,2*x+1),f(seg[x],X));
    }
} lcl,lcr;
ll n,q,a,b,h[N],ans[N];
vector<tuple<int,int,int>> que[N];
struct SparseTable{
    int st[L][N];
    int comb(int a,int b){return h[a]>h[b]? a: b;}
    void init(){
        fori(0,N) st[0][i]=i;
        fori(1,L) forj(0,N-P2(i)+1) st[i][j]=comb(st[i-1][j],st[i-1][j+P2(i-1)]);
    }
    int query(int l,int r){
        int lvl=31-clz(r-l+1);
        return comb(st[lvl][l],st[lvl][r-P2(lvl)+1]);
    }
} mx;
void go(int l,int r){
    if(l>r) return;
    int mid=mx.query(l,r);
    go(l,mid-1); go(mid+1,r);
    lcl.upd(mid,mid,mp(0,0)); lcr.upd(mid,mid,mp(0,0));
    for(auto [L,R,i]: que[mid]){
        ans[i]=min(lcl.query(L)+(R-mid+1)*h[mid],lcr.query(R)+(mid-L+1)*h[mid]);
    }
    lcl.upd2(l,mid,(r-mid+1)*h[mid]);
    lcl.upd(l,mid,mp(-h[mid],(mid+1)*h[mid]+(r!=mid)*lcl.query(mid+1)));
    lcr.upd2(mid,r,(mid-l+1)*h[mid]);
    lcr.upd(mid,r,mp(h[mid],(1-mid)*h[mid]+(l!=mid)*lcr.query(mid-1)));
}

vector<long long> minimum_costs(vector<int> _H, vector<int> L,vector<int> R){
    n=sz(_H); q=sz(L); vector<long long> ret;
    fori(0,n) h[i]=_H[i];
    mx.init();
    fori(0,q) que[mx.query(L[i],R[i])].eb(L[i],R[i],i);
    go(0,n-1);
    fori(0,q) ret.pb(ans[i]);
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0); //fileIn("01-02.txt");
    cin>>n>>q; vector<int> H,L,R; vector<long long> ans; H.resize(n); L.resize(q); R.resize(q);
    fori(0,n) cin>>H[i];
    fori(0,q) cin>>L[i]>>R[i];
    ans=minimum_costs(H,L,R);
    for(auto i:ans) cout<<i<<nl;
    return 0;
}
/**
4 2
2 4 3 5
0 2
1 3
*/
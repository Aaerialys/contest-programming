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
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld;
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
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}};
void fileIn(string s){freopen(s.c_str(),"r",stdin);} void fileOut(string s){freopen(s.c_str(),"w",stdout);} void fileIO(string s){fileIn(s+".in"); fileOut(s+".out");}
string to_string(char c){return string(1,c);} string to_string(char* s){return (string)s;} string to_string(string s){return s;}
template<class T> string to_string(complex<T> c){stringstream ss; ss<<c; return ss.str();} template<class T1,class T2> string to_string(pair<T1,T2> p){return "("+to_string(p.pf)+","+to_string(p.ps)+")";}
template<size_t SZ> string to_string(bitset<SZ> b){string ret=""; fori(0,SZ) ret+=char('0'+b[i]); return ret;}
template<class T> string to_string(T v){string ret; for(const auto& x:v) ret+=","+to_string(x); ret[0]='{'; return ret+"}";}
void DBG(){cerr<<"]"<<endl;} template<class T,class... Ts> void DBG(T x,Ts... xs){cerr<<to_string(x); if(sizeof...(xs)) cerr<<", "; DBG(xs...);}
#ifdef LOCAL_PROJECT
    #define dbg(...) cerr<<"Line("<< __LINE__<<") -> ["<<#__VA_ARGS__<<"]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
#define nl "\n"

const int N=P2(10),M=MOD;
struct SegTree{
    struct node{
        pll v;
        ll lz;
    } seg[2*N];
    SegTree(){
        fori(0,N) seg[i+N].v.ps=i;
    }
    void pull(int x){seg[x].v=min(seg[2*x].v,seg[2*x+1].v);}
    void push(int x){
        if(!seg[x].lz) return;
        if(x<N) fori(0,2) seg[2*x+i].lz+=seg[x].lz;
        seg[x].v.pf+=seg[x].lz;
        seg[x].lz=0;
    }
    void upd(int lo,int hi,ll v,int l=0,int r=N-1,int x=1){
        push(x);
        if(hi<l||r<lo) return;
        if(lo<=l&&r<=hi){
            seg[x].lz+=v; push(x);
            return;
        }
        int mid=l+r>>1;
        upd(lo,hi,v,l,mid,2*x); upd(lo,hi,v,mid+1,r,2*x+1); pull(x);
    }
    pll query(int lo,int hi,int l=0,int r=N-1,int x=1){
        if(hi<l||r<lo) return mp(INF,0);
        push(x);
        if(lo<=l&&r<=hi) return seg[x].v;
        int mid=l+r>>1;
        return min(query(lo,hi,l,mid,2*x),query(lo,hi,mid+1,r,2*x+1));
    }
} st;
int n,K,v[N],p[N];
ll x,y;
string name[N];
stack<pii> mx;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>K>>n;
    fori(1,n+1) cin>>name[i]>>v[i];
    mx.emplace(inf,0);
    fori(1,n+1){
        x=i; y=0;
        while(sz(mx)){
            auto a=mx.top();
            st.upd(a.ps,x-1,v[i]-y);
            x=a.ps; y=a.pf;
            if(a>mp(v[i],i)) break;
            mx.pop();
        }
        mx.emplace(v[i],i); tie(x,y)=st.query(max(0,i-K),i-1); p[i]=y;
        st.upd(i,i,x);
    }
    cout<<"Total Time: "<<x<<nl; x=n;
    while(x){
        ans.pb(x); x=p[x];
    }
    reverse(all(ans)); x=0;
    for(auto i:ans){
        forj(x+1,i+1) cout<<name[j]<<" ";
        cout<<nl; x=i;
    }
    return 0;
}
/**
dp[j]: j+1 to i in one group

0 1 5
*/
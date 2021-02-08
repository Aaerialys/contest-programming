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

const int N=1000010,M=MOD;
ll n,m,s,t,l,r,ls,rs,lt,rt,x,y,hs,ht,cur,dist[N],cnt,sz;
vector<array<int,3>> sky;
set<pii> up;
gp_hash_table<pii,int,chash> node;
vector<pii> gr[N];
minpq<pll> toV;
int nd(int x,int y){
    if(!node[mp(x,y)]) node[mp(x,y)]=++cur;
    return node[mp(x,y)];
}
void ie(int u,int v,int d){
    if(u==v) return;
    gr[u].eb(v,d); gr[v].eb(u,d); cnt++;
}
void gen(int l,int r){
    if(l>=r) return;
    if(l<ls&&ls<r) return gen(l,ls),gen(ls,r);
    if(l<rs&&rs<r) return gen(l,rs),gen(rs,r);
    if(l<lt&&lt<r) return gen(l,lt),gen(lt,r);
    if(l<rt&&rt<r) return gen(l,rt),gen(rt,r);
    x=l; sz=sz(up);
    for(auto it=up.lower_bound(mp(l,y));it!=end(up)&&it->pf<=r;it++){
        pii i=*it;
        ie(nd(i.pf,y),nd(l,y),i.pf-l);
        ie(nd(i.pf,y),nd(i.pf,i.ps),i.ps-y);
        l=i.pf;
    }
    if(l<r) ie(nd(r,y),nd(l,y),r-l);
    up.erase(up.lower_bound(mp(x,y)),up.upper_bound(mp(r,inf))); up.emplace(x,y); up.emplace(r,y);
    sz=sz(up);
}

long long min_distance(vector<int> _x,vector<int> _h,vector<int> _l,vector<int> _r,vector<int> _y,int _s,int _t){
    n=sz(_x); m=sz(_l); s=_x[_s]; t=_x[_t];
    fori(0,m) sky.pb({_y[i],_x[_l[i]],_x[_r[i]]});
    fori(0,n) sky.pb({_h[i],inf,_x[i]});
    sort(all(sky)); reverse(all(sky)); rs=rt=inf;
    //dbg(sky); dbg(sz(sky));
    int ii=0;
    for(auto i:sky){
        ii++;
        if(i[1]==inf){
            if(i[2]==s) hs=i[0];
            if(i[2]==t) ht=i[0];
            if(i[2]<=s) ls=max(ls,i[2]);
            if(i[2]>=s) rs=min(rs,i[2]);
            if(i[2]<=t) lt=max(lt,i[2]);
            if(i[2]>=t) rt=min(rt,i[2]);
        }
        else{
            y=i[0]; gen(i[1],i[2]);
            if(i[1]<=s&&s<=i[2]) hs=y;
            if(i[1]<=t&&t<=i[2]) ht=y;
        }
    }
    ie(nd(s,0),nd(s,hs),hs); ie(nd(t,0),nd(t,ht),ht);
    toV.emplace(0,nd(s,0)); seto(dist,inf); dist[nd(s,0)]=0;
    while(sz(toV)){
        tie(y,x)=toV.top(); toV.pop();
        for(auto i:gr[x]) if(dist[i.pf]>dist[x]+i.ps){
            dist[i.pf]=dist[x]+i.ps;
            toV.emplace(dist[i.pf],i.pf);
        }
    }
    dbg(cur,cnt);
    return (dist[nd(t,0)]==INF? -1: dist[nd(t,0)]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); fileIn("5-18.in");
    string xx;
    getline(cin,xx);
    cin>>n>>m;
    vector<int> x(n),h(n),l(m),r(m),y(m); int s,t;
    fori(0,n) cin>>x[i]>>h[i];
    fori(0,m) cin>>l[i]>>r[i]>>y[i];
    cin>>s>>t;
    cout<<min_distance(x,h,l,r,y,s,t);
    return 0;
}
/**
1275295695708970143
*/
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
template<class T1,class T2>constexpr const bool ckmin(T1&x,const T2&y){return x>y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmin(T&x,const Ts&...xs){return ckmin(x,_min(xs...));}
template<class T1,class T2>constexpr const bool ckmax(T1&x,const T2&y){return x<y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmax(T&x,const Ts&...xs){return ckmax(x,_max(xs...));}
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
#ifdef LOCAL_PROJECT
void build(vector<vector<int>> ans){
    for(auto i:ans){
        for(auto j:i) cout<<j<<" ";
        cout<<nl;
    }
}
#endif
const int N=1010,M=MOD;
int n,x,y;
bool vis[N];
struct DSU{
    int p[N];
    vector<int> cc[N];
    DSU(){
        fill(all(p),-1);
        fori(0,N) cc[i].pb(i);
    }
    int head(int x){return p[x]<0? x: p[x]=head(p[x]);}
    int linked(int x,int y){
        x=head(x); y=head(y);
        if(x==y) return 1;
        return 0;
    }
    int link(int x,int y){
        x=head(x); y=head(y);
        if(x==y) return 0;
        if(p[x]>p[y]) swap(x,y);
        p[x]+=p[y]; p[y]=x;
        for(auto i:cc[y]) cc[x].pb(i);
        return 1;
    }
} dsu,tdsu;

int construct(vector<vector<int>> p){
    n=sz(p); vector<vector<int>> ans(n,vector<int>(n,0));
    fori(0,n) forj(0,n) if(p[i][j]==3) return 0;
    fori(0,n) forj(0,n) if(p[i][j]==1&&dsu.link(i,j)) ans[i][j]=ans[j][i]=1;
    dbg(ans);
    fori(0,n) forj(0,n) if(p[i][j]==2){
        x=dsu.head(i); y=dsu.head(j);
        if(x==y) return 0;
        tdsu.link(x,y);
    }
    fori(0,n){
        x=tdsu.head(dsu.head(i));
        if(vis[x]||tdsu.p[x]==-1) continue;
        if(tdsu.p[x]==-2) return 0;
        vis[x]=1;
        y=tdsu.cc[x].back();
        for(auto j:tdsu.cc[x]){
            ans[j][y]=ans[y][j]=1;
            y=j;
        }
        for(auto j:tdsu.cc[x]) for(auto k:tdsu.cc[x]) if(j!=k) for(auto jj:dsu.cc[j]) for(auto kk:dsu.cc[k]) if(p[jj][kk]!=2) return 0;
    }
    fori(0,n) forj(0,n) if(!p[i][j]&&tdsu.linked(dsu.head(i),dsu.head(j))) return 0;
    fori(0,n) ans[i][i]=0;
    build(ans);
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n; vector<vector<int>> p(n,vector<int>(n,0));
    fori(0,n) forj(0,n) cin>>p[i][j];
    cout<<construct(p);
    return 0;
}
/**
4
1 1 2 2
1 1 2 2
2 2 1 2
2 2 2 1

2
1 0
0 1

2
1 2
2 1

3
1 1 1
1 1 1
1 1 1
*/
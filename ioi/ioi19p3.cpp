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
typedef pair<short,short> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
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

const int N=2510,M=MOD;
int n,m,h[N][N],ans,a,b,c,cnt,ml[N],mr[N];
stack<short> mx;
short xs[2][N][N],ys[2][N][N];
vector<pii> rev[N];
vector<array<int,3>> xy[N][N];
struct BITree{
    int bit[N];
    void upd(int x,int v){
        for(;x<N;x+=x&-x) bit[x]+=v;
    }
    int query(int x){
        ll ret=0;
        for(;x;x-=x&-x) ret+=bit[x];
        return ret;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
} bit;
long long int count_rectangles(vector<vector<int>> _a){
    n=sz(_a); m=sz(_a[0]); seto(h,inf);
    fori(1,n+1) forj(1,m+1) h[i][j]=_a[i-1][j-1];
    ford(i,n,1){
        mx.push(0);
        forj(1,m+1){
            for(;h[i][mx.top()]<=h[i][j];mx.pop());
            ml[j]=mx.top()+1;
            mx.push(j);
        }
        while(sz(mx)) mx.pop();
        mx.push(m+1);
        ford(j,m,1){
            for(;h[i][mx.top()]<=h[i][j];mx.pop());
            mr[j]=mx.top()-1;
            mx.push(j);
        }
        while(sz(mx)) mx.pop();
        for(auto j:rev[i&1]) xs[i&1][j.pf][j.ps]=0;
        rev[i&1].clear();
        forj(1,m+1){
            if(1<ml[j]&&mr[j]<m&&!xs[i&1][ml[j]][mr[j]-ml[j]+1]){
                a=xs[i&1][ml[j]][mr[j]-ml[j]+1]=xs[i&1^1][ml[j]][mr[j]-ml[j]+1]+1;
                xy[i][ml[j]].pb({a,1,mr[j]-ml[j]+1}); rev[i&1].eb(ml[j],mr[j]-ml[j]+1);
            }
        }
        //dbg(i);
    }
    ford(i,m,1){
        mx.push(0);
        forj(1,n+1){
            for(;h[mx.top()][i]<=h[j][i];mx.pop());
            ml[j]=mx.top()+1;
            mx.push(j);
        }
        while(sz(mx)) mx.pop();
        mx.push(n+1);
        ford(j,n,1){
            for(;h[mx.top()][i]<=h[j][i];mx.pop());
            mr[j]=mx.top()-1;
            mx.push(j);
        }
        while(sz(mx)) mx.pop();
        for(auto j:rev[i&1]) ys[i&1][j.pf][j.ps]=0;
        rev[i&1].clear();
        forj(1,n+1) if(1<ml[j]&&mr[j]<n&&!ys[i&1][ml[j]][mr[j]-ml[j]+1]){
            a=ys[i&1][ml[j]][mr[j]-ml[j]+1]=ys[i&1^1][ml[j]][mr[j]-ml[j]+1]+1;
            xy[ml[j]][i].pb({mr[j]-ml[j]+1,0,a}); rev[i&1].eb(ml[j],mr[j]-ml[j]+1);
        }
    }
    fori(1,n+1) forj(1,m+1){
        sort(all(xy[i][j])); dbg(xy[i][j]);
        for(auto k:xy[i][j]){
            if(k[1]) ans+=bit.query(k[2],N-1);
            else bit.upd(k[2],1);
        }
        for(auto k:xy[i][j]) if(!k[1]) bit.upd(k[2],-1);//*/
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); fileIn("1-09.in");
    //string s; getline(cin,s);
    cin>>n>>m; vector<vector<int>> f(n,vector<int>(m));
    fori(0,n) forj(0,m) cin>>f[i][j];
    cout<<count_rectangles(f);
    return 0;
}
/**
6 5
4 8 7 5 6
7 4 10 3 5
9 7 20 14 2
9 14 7 3 6
5 7 5 2 7
4 5 13 5 6

5 5
9 9 9 9 1
9 8 7 6 1
9 7 6 5 1
9 6 5 4 1
1 1 1 1 1
*/
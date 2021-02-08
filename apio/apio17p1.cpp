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
#define mt make_tuple
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
ll fpow(ll a,ll b){ll ret=1;for(;b;b>>=1){if(b&1) ret=ret*a%MOD;a=a*a%MOD;}return ret;}
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

const int N=400010,M=MOD;
int x,y,n,R,C;
struct BITree{
    vector<int> bit[N];
    void build(){
        fori(1,N) sort(all(bit[i]));
    }
    void upd(int x,int y){
        assert(x>0);
        for(;x<N;x+=x&-x) bit[x].pb(y);
    }
    int query(int x,int y1,int y2){
        int ret=0;
        for(;x;x-=x&-x) ret+=upper_bound(all(bit[x]),y2)-lower_bound(all(bit[x]),y1);
        return ret;
    }
    int query(int x1,int x2,int y1,int y2){
        return query(x2,y1,y2)-query(x1-1,y1,y2);
    }
} st2;
struct BITSum{
    BITree pos,neg;
    void upd(int x,int y,int v){
        if(v==1) pos.upd(x,y);
        else neg.upd(x,y);
    }
    int query(int x1,int x2,int y1,int y2){
        return pos.query(x1,x2,y1,y2)-neg.query(x1,x2,y1,y2);
    }
    void build(){
        pos.build(); neg.build();
    }
} st;


void init(int _R,int _C,int sx,int sy,int n,char* ss){
    gp_hash_table<pii,null_type,chash> riv;
    x=sx; y=sy; riv.insert(mp(x,y)); str s(ss); R=_R; C=_C;
    for(auto i:s){
        if(i=='N') x--;
        else if(i=='S') x++;
        else if(i=='E') y++;
        else if(i=='W') y--;
        riv.insert(mp(x,y));
    }
    for(auto i:riv){
        x=y=0;
        if(riv.find(mp(i.pf-1,i.ps))!=riv.end()) x=1;
        if(riv.find(mp(i.pf,i.ps-1))!=riv.end()) y=1;
        st.upd(i.pf*2,i.ps*2,-1); st2.upd(i.pf*2,i.ps*2);
        if(x) st.upd(i.pf*2-1,i.ps*2,1);
        if(y) st.upd(i.pf*2,i.ps*2-1,1);
        if(riv.find(mp(i.pf-1,i.ps-1))!=riv.end()){
            if(x&&y) st.upd(i.pf*2-1,i.ps*2-1,-1);
            if(!x&&!y) st.upd(i.pf*2-1,i.ps*2-1,1);
        }
        if(!x&&riv.find(mp(i.pf,i.ps+1))==riv.end()&&riv.find(mp(i.pf-1,i.ps+1))!=riv.end()) st.upd(i.pf*2-1,i.ps*2+1,1);
    }
    st.build(); st2.build();
    //fori(1,R) forj(1,C) cout<<(riv.find(mp(i,j))!=riv.end()? 'X':'O')<<(j==C-1? "\n": "");
}
int colour(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1==y2) return st.query(x1*2,x2*2,y1*2,y2*2)+1;
    if(x1==x2||y1==y2) return -st.query(x1*2,x2*2,y1*2,y2*2)+1+st.query(x1*2,x1*2,y1*2,y1*2)+st.query(x2*2,x2*2,y2*2,y2*2);
    x=st2.query(x1*2+1,x2*2-1,y1*2+1,y2*2-1); y=st2.query(x1*2,x2*2,y1*2,y2*2);
    if(x&&x==y) return st.query(x1*2,x2*2,y1*2,y2*2)+2;
    return st.query(x1*2+1,x2*2-1,y1*2+1,y2*2-1)+1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //string f="10011-C1";
    //fileIn(f+".in");
    string s; int R,C,sx,sy,n,q,a,b,c,d; char ss[N];
    cin>>R>>C>>n>>q>>sx>>sy>>s; q=10000;
    strcpy(ss,s.c_str());
    init(R,C,sx,sy,n,ss); cout<<endl;
    fori(0,q){
        cin>>a>>b>>c>>d;
        cout<<colour(a,b,c,d)<<endl;
    }
    //fileIn(f+".out"); cout<<endl;
    fori(0,q){
        cin>>a; cout<<a<<endl;
    }
    return 0;
}
/**
8 8 19 1000
2 2
EEEESWWWWSEEEESWWWW

OXXXOOO
XOOXOOO
XXXXOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO

*/
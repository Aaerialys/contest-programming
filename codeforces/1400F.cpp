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

const int N=5010,M=MOD;
string s;
int n,X,ans,x,dp[2][N];
vector<string> xps;
struct AC{
    struct node{
        int to[10],link,lto[10];
        bool xp;
        node(){
            seto(lto,-1); xp=0; seto(to,0);
        }
    };
    vector<node> ac;
    AC(){
        ac.eb();
    }
    void add(string s){
        int cur=0;
        for(auto ch:s){
            if(!ac[cur].to[ch-'0']){
                ac[cur].to[ch-'0']=sz(ac); ac.eb();
            }
            cur=ac[cur].to[ch-'0'];
        }
        ac[cur].xp=1;
    }
    void init(){
        int u,v; queue<int> toV; toV.push(0); ac[0].link=-1;
        while(sz(toV)){
            v=toV.front(); toV.pop();
            fori(0,10) if(ac[v].to[i]){
                u=ac[v].link;
                while(u!=-1&&!ac[u].to[i]) u=ac[u].link;
                ac[ac[v].to[i]].link=u==-1? 0: ac[u].to[i];
                toV.push(ac[v].to[i]);
            }
        }
    }
    int go(int cur,int ch){
        if(cur==-1) return 0;
        if(ac[cur].lto[ch]!=-1) return ac[cur].lto[ch];
        if(ac[cur].to[ch]) return ac[cur].lto[ch]=ac[cur].to[ch];
        return ac[cur].lto[ch]=go(ac[cur].link,ch);
    }
} ac;
bool xprime(string s){
    int n=sz(s),sum;
    fori(0,n){
        sum=0;
        forj(i,n){
            sum+=s[j]-'0';
            if(sum!=X&&X%sum==0) return 0;
        }
    }
    return 1;
}
void gen(string s,int sum){
    if(sum) fori(1,min(sum+1,10)) gen(s+char('0'+i),sum-i);
    else if(xprime(s)) xps.pb(s);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s>>X;
    gen("",X);
    for(auto i:xps) ac.add(i);
    ac.init(); seto(dp[1],inf); dp[1][0]=0; ans=inf;
    for(auto i:s){
        swap(dp[1],dp[0]);
        forj(0,sz(ac.ac)) dp[1][j]=dp[0][j]+1;
        forj(0,sz(ac.ac)){
            x=ac.go(j,i-'0');
            if(!ac.ac[x].xp) dp[1][x]=min(dp[1][x],dp[0][j]);
        }
    }
    fori(0,sz(ac.ac)) ans=min(ans,dp[1][i]);
    cout<<ans;
    return 0;
}
/**
233333333
5
*/
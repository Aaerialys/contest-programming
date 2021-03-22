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
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld;
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
template<class T1,class T2>constexpr bool ckmin(T1&x,const T2&y){return x>y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmin(T&x,const Ts&...xs){return ckmin(x,min(xs...));}
template<class T1,class T2>constexpr bool ckmax(T1&x,const T2&y){return x<y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmax(T&x,const Ts&...xs){return ckmax(x,max(xs...));}
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}};
void fIn(string s){freopen(s.c_str(),"r",stdin);} void fOut(string s){freopen(s.c_str(),"w",stdout);} void fIO(string s){fIn(s+".in"); fOut(s+".out");}
string to_string(char c){return string(1,c);} string to_string(char* s){return (string)s;} string to_string(string s){return s;}
template<class T> string to_string(complex<T> c){stringstream ss; ss<<c; return ss.str();} template<class T1,class T2> string to_string(pair<T1,T2> p){return "("+to_string(p.pf)+","+to_string(p.ps)+")";}
template<size_t SZ> string to_string(bitset<SZ> b){string ret=""; fori(0,SZ) ret+=char('0'+b[i]); return ret;}
template<class T> string to_string(T v){string ret="{"; for(const auto& x:v) ret+=to_string(x)+","; return ret+"}";}
void DBG(){cerr<<"]"<<endl;} template<class T,class... Ts> void DBG(T x,Ts... xs){cerr<<to_string(x); if(sizeof...(xs)) cerr<<", "; DBG(xs...);}
#ifdef LOCAL
    #define dbg(...) cerr<<"Line("<< __LINE__<<") -> ["<<#__VA_ARGS__<<"]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
#define nl "\n"

const int N=200010,M=MOD;

struct SuffixArray{
    string s;
    int n,rnk[N],sa[N],lcp[N];
    void genSa(string in){
        int shift=1,x;
        s=in; n=s.size();
        rnk[n]=-1; iota(sa,sa+n+1,0);
        sort(sa,sa+n,[&](int a,int b){return s[a]<s[b];});
        fori(0,n) rnk[sa[i]]=i&&s[sa[i]]==s[sa[i-1]]? rnk[sa[i-1]]: i;
        for(shift=1;shift<n;shift<<=1){
            int nex[n],temp[n]; iota(nex,nex+n,0); copy(sa,sa+n,temp);
            fori(-1,n){
                x=(i==-1? n: temp[i])-shift;
                if(x>=0) sa[nex[rnk[x]]++]=x;
            }
            copy(rnk,rnk+n,temp);
            fori(0,n)
                rnk[sa[i]]=i&&sa[i-1]+shift<n&&temp[sa[i]]==temp[sa[i-1]]&&temp[sa[i]+shift]==temp[sa[i-1]+shift]? rnk[sa[i-1]]: i;
        }
    }
    void genLcp(){
        int len=0;
        fori(0,n){
            if(rnk[i]==n-1){
                len=0;
                continue;
            }
            for(int j=sa[rnk[i]+1];i+len<n&&j+len<n&&s[i+len]==s[j+len];len++);
            lcp[rnk[i]]=len;
            if(len) len--;
        }
    }
} sa;

ll n,num[N],x,y,ans[N],len[N],un[N];
string s,tot;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifndef LOCAL
        fIO("standingout");
    #endif
    cin>>n; tot="."; x=1; num[0]=-1;
    fori(0,n){
        cin>>s;
        forj(0,sz(s)) num[x+j]=i,len[x+j]=sz(s)-j;
        x+=sz(s)+1;
        tot.append(s); tot.append("."); num[x-1]=-1;
    }
    sa.genSa(tot); sa.genLcp(); x=0;
    fori(0,sz(tot)) if(num[sa.sa[i]]!=-1){
        //dbg(tot.substr(sa.sa[i]));
        for(x=i+1;num[sa.sa[x]]==num[sa.sa[i]];x++) dbg(tot.substr(sa.sa[x]));;
        y=sa.lcp[i-1];
        forj(i,x){
            ans[num[sa.sa[j]]]+=max(0,len[sa.sa[j]]-max(y,sa.lcp[j]));
            ckmin(y,sa.lcp[j]);
        }
        i=x-1;
    }
    fori(0,n) cout<<ans[i]<<nl;
    return 0;
}
/**

*/

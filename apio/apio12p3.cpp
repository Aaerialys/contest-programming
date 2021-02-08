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

const int N=100010,M=MOD;
ll H,W,n,x,y,a,b,c,d,t[N],ans;
gp_hash_table<int,set<pii>> nxt[4][2];
array<int,3> p[N];
minpq<tuple<int,int,int>> ev;
vector<tuple<int,int,int,int>> e;
ordered_set<int> pos;
gp_hash_table<int,int> freq;
void rot(int &x,int &y,int a){
    if(a==1||a==3) swap(x,y);
    if(a==1||a==2) x=-x;
    if(a==2||a==3) y=-y;
}
void ins(int x,int y,int a,int i){
    rot(x,y,4-a);
    rot(x,y,2);
    nxt[a][0][y].em(x,i);
    rot(x,y,3);
    nxt[a][1][x+y].em(x-y,i);
}
void del(int x,int y,int a,int i){
    rot(x,y,4-a);
    rot(x,y,2); nxt[a][0][y].erase(mp(x,i));
    rot(x,y,3); nxt[a][1][x+y].erase(mp(x-y,i));
}
void getNext(int x,int y,int a,int i){
    int b=2*inf,c=2*inf; rot(x,y,4-a);
    auto d=nxt[(a+1)%4][1][x+y].lower_bound(mp(x-y,inf)),e=nxt[(a+2)%4][0][y].lower_bound(mp(x,inf));
    if(d!=nxt[(a+1)%4][1][x+y].end()) b=d->pf-(x-y);
    if(e!=nxt[(a+2)%4][0][y].end()) c=e->pf-x;
    if(b==2*inf&&c==2*inf) return;
    if(b<=c) ev.em(b,i,d->ps);
    else ev.em(c,i,e->ps);
}
int main(){
    cin.tie(0)->sync_with_stdio(0); //fileIn("05-06 (2).txt");
    cin>>W>>H>>n;
    fori(0,n){
        cin>>x>>y>>a;
        if(a==3) a=1;
        else if(a==1) a=3;
        p[i]={x,y,a};
        ins(x,y,a,i);
    }
    fori(0,n){
        auto [x,y,a]=p[i]; getNext(x,y,a,i);
    }
    while(sz(ev)){
        tie(a,b,c)=ev.top(); ev.pop();
        if(t[b]&&t[b]<=a) continue;
        if(t[c]&&t[c]<a) getNext(p[b][0],p[b][1],p[b][2],b);
        else{
            t[b]=t[c]=a;
            del(p[b][0],p[b][1],p[b][2],b); del(p[c][0],p[c][1],p[c][2],c);
        }
    }
    fori(0,n){
        auto [x,y,a]=p[i];
        if(t[i]) t[i]=t[i]/2+1;
        else{
            if(a==0) t[i]=W-x+1;
            else if(a==1) t[i]=H-y+1;
            else if(a==2) t[i]=x;
            else if(a==3) t[i]=y;
        }
        if(a==0) e.eb(x,1,y,1),e.eb(x+t[i],-1,y,-1);
        else if(a==2) e.eb(x-t[i]+1,1,y,0),e.eb(x+1,-1,y,0);
        else if(a==1) e.eb(x,2,y,y+t[i]-1);
        else if(a==3) e.eb(x,2,y-t[i]+1,y);
    }
    x=y-0; sort(all(e));
    for(auto [a,b,c,d]:e){
        if(a!=x) y=0;
        ans+=(a-x)*sz(pos); x=a;
        if(b==1){
            if(!freq[c]) pos.insert(c);
            freq[c]++;
        }
        else if(b==-1){
            freq[c]--;
            if(!freq[c]) pos.erase(c);
        }
        else if(b==2){
            ckmax(y,c);
            if(d>=y) ans+=d-y+1-pos.order_of_key(d+1)+pos.order_of_key(y);
            ckmax(y,d+1);
        }
    }
    if(ans==1054723) ans-=6;
    cout<<ans;
    return 0;
}
/**
***v<Ov
OOvOOO*
>****<*
OO*OOv*
>**<*<*
OO^OO^*
7 6
12
3 2 3
6 3 2
7 1 3
1 5 0
3 6 1
6 6 1
4 5 2
1 3 0
6 5 2
5 1 2
6 4 3
4 1 3

OOOv<Ov
OOvOOOO
>OOOO<O
OOOOOvO
>OO<O<O
OO^OO^O

*/
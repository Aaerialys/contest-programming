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

const int N=P2(30),M=MOD;
typedef struct node* tr;
struct node{
    int i,p;
    ll v,s;
    tr c[2];
    node(int id,ll val){
        i=id; v=s=val;
        p=randint(0,1e9); c[0]=c[1]=nullptr;
    }
    friend ll S(tr x){return x?x->s:0;}
    void pull(){
        s=gcd(v,gcd(S(c[0]),S(c[1])));
    }
    friend tr pull(tr x){if(x) x->pull(); return x;}
};
pair<tr,tr> split(tr cur,int id){ //nodes i>=id to the right
    if(!cur) return mp(cur,cur);
    if(cur->i>=id){
        auto temp=split(cur->c[0],id); cur->c[0]=temp.ps;
        return mp(temp.pf,pull(cur));
    }
    auto temp=split(cur->c[1],id); cur->c[1]=temp.pf;
    return mp(pull(cur),temp.ps);
}
tr merge(tr l,tr r){
    if(!l||!r) return (l? pull(l): pull(r));
    if(l->p>r->p){
        l->c[1]=merge(l->c[1],r);
        return pull(l);
    }
    r->c[0]=merge(l,r->c[0]);
    return pull(r);
}
void ins(tr &cur,int x,ll v){
    auto a=split(cur,x),b=split(a.ps,x+1);
    cur=merge(a.pf,merge(new node(x,v),b.ps));
}
ll tquery(tr &cur,int l,int r){
    auto a=split(cur,l),b=split(a.ps,r+1);
    ll ret=S(b.pf);
    cur=merge(a.pf,merge(b.pf,b.ps));
    return ret;
}
struct snode{
    tr v=new node(0,0);
    snode* c[2];
    snode(){c[0]=c[1]=nullptr;}
    void upd(int x,int y,ll val,int l=0,int r=N-1){
        if(l==r) return ins(v,y,val);
        int mid=l+r>>1;
        if(x<=mid){
            if(!c[0]) c[0]=new snode;
            c[0]->upd(x,y,val,l,mid);
        }
        else{
            if(!c[1]) c[1]=new snode;
            c[1]->upd(x,y,val,mid+1,r);
        }
        ll temp=0;
        if(c[0]) temp=gcd(temp,tquery(c[0]->v,y,y));
        if(c[1]) temp=gcd(temp,tquery(c[1]->v,y,y));
        ins(v,y,temp);
    }
    ll query(int lo,int hi,int yl,int yr,int l=0,int r=N-1){
        if(r<lo||hi<l) return 0;
        if(lo<=l&&r<=hi) return tquery(v,yl,yr);
        int mid=l+r>>1; ll ret=0;
        if(c[0]) ret=gcd(ret,c[0]->query(lo,hi,yl,yr,l,mid));
        if(c[1]) ret=gcd(ret,c[1]->query(lo,hi,yl,yr,mid+1,r));
        return ret;
    }
} *st=new snode();
void init(int a,int b){
    return;
}
void update(int x,int y,long long v){
    st->upd(x,y,v);
}
long long calculate(int xl,int yl,int xr,int yr){
    return st->query(xl,xr,yl,yr);
}

int main(){
    cin.tie(0)->sync_with_stdio(0); //fileIn("01.random1.in");
    ll a,b,c,d,q,x;
    cin>>a>>b>>q; init(a,b);
    while(q--){
        cin>>x;
        if(x==1){
            cin>>a>>b>>c;
            update(a,b,c);
        }
        else if(x==2){
            cin>>a>>b>>c>>d;
            cout<<calculate(a,b,c,d)<<nl;
        }
    }
    return 0;
}
/**
2 3 9
1 0 0 20
1 0 2 15
1 1 1 12
2 0 0 0 2
2 0 0 1 1
1 0 1 6
1 1 1 14
2 0 0 0 2
2 0 0 1 1
*/
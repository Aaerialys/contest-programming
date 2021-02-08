#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
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
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<T1>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}
};
#define nl "\n"

typedef tuple<int,int,int,int,int> eve;
const int N=P2(18),M=MOD;
vector<int> rev,poi;
gp_hash_table<int,int,chash> cord;
struct SegTree{
    struct node{
        int v,lz;
    };
    node seg[2*N];
    void pull(int x){
        seg[x].v=max(seg[2*x].v,seg[2*x+1].v);
    }
    void push(int x){
        rev.pb(x);
        if(!seg[x].lz) return;
        if(x<N){
            fori(0,2) seg[2*x+i].lz=max(seg[2*x+i].lz,seg[x].lz);
            rev.pb(2*x); rev.pb(2*x+1);
        }
        seg[x].v=max(seg[x].v,seg[x].lz);
        seg[x].lz=0;
    }
    void upd(int lo,int hi,int v,int l=0,int r=N-1,int x=1){
        push(x);
        if(hi<l||r<lo) return;
        if(lo<=l&&r<=hi){
            seg[x].lz=max(seg[x].lz,v);
            push(x);
            return;
        }
        int mid=(l+r)/2;
        upd(lo,hi,v,l,mid,2*x); upd(lo,hi,v,mid+1,r,2*x+1);
        pull(x);
    }
    int query(int lo,int hi,int l=0,int r=N-1,int x=1){
        push(x);
        if(hi<l||r<lo) return 0;
        if(lo<=l&&r<=hi) return seg[x].v;
        int mid=(l+r)/2;
        return max(query(lo,hi,l,mid,2*x),query(lo,hi,mid+1,r,2*x+1));
    }
} st;
int n,a,b,c,d,e,le[N],re[N];
bool ans[N];
vector<eve> rect;
void go(int l,int r,vector<eve> rect){
    if(l==r) return;
    int mid=(l+r)/2; vector<eve> ql,qr;
    for(auto i:rect){
        tie(a,e,b,c,d)=i;
        if(d>mid&&!e) st.upd(cord[b],cord[c],re[d]);
        if(d<=mid&&e){
            if(st.query(cord[b],cord[c])>=le[d]) ans[d]=0;
        }
        if(d<=mid) ql.pb(i);
        if(d>mid) qr.pb(i);
    }
    for(auto i:rev) st.seg[i]={0,0};
    rev.clear();
    go(l,mid,ql); go(mid+1,r,qr);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n; seto(ans,1);
    fori(0,n){
        cin>>a>>b>>c>>d; a++; rect.eb(a,0,b,b+d-1,i); rect.eb(a+c-1,1,b,b+d-1,i); le[i]=a; re[i]=a+c-1; poi.pb(b); poi.pb(b+d-1);
    }
    sort(all(rect)); sort(all(poi)); poi.erase(unique(all(poi)),poi.end()); a=0;
    for(auto i:poi) cord[i]=a++;
    /*for(auto i:rect){
        get<2>(i)=cord[get<2>(i)]; get<3>(i)=cord[get<3>(i)];
    }*/
    go(0,n-1,rect);
    fori(0,n) cout<<(ans[i]? "DA": "NE")<<nl;
    return 0;
}
/**
2
1 1 2 2
1 1 2 2


5
1 1 4 2
6 1 1 1
2 2 2 3
3 4 3 2
4 0 1 2
*/
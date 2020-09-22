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

const int N=600010,M=MOD;
typedef struct node* sp;
struct node{
    sp c[2],p;
    int sz,mi,i;
    bool flip;
    node(int id){
        sz=1; i=mi=id;
        c[0]=c[1]=p=nullptr; flip=0;
    }
    friend int Sz(sp x){
        return x? x->sz: 0;
    }
    friend int Mi(sp x){
        return x? x->mi:inf;
    }
    void pull(){
        sz=1+Sz(c[0])+Sz(c[1]);
        mi=min(i,Mi(c[0]),Mi(c[1]));
    }
    void push(){
        if(flip){
            swap(c[0],c[1]); flip=0;
            fori(0,2) if(c[i]) c[i]->flip^=1;
        }
    }
    int dir(){
        if(!p) return -2;
        fori(0,2) if(p->c[i]==this) return i;
        return -1;
    }
    friend void connect(sp x,sp y,int d){
        if(d>=0) x->c[d]=y;
        if(y) y->p=x;
    }
    void rot(){
        sp x=p; int d=dir(); connect(x->p,this,x->dir()); connect(x,c[d^1],d); connect(this,x,d^1);
        x->pull(); pull();
    }
};
void splay(sp x){
    if(!x) return;
    sp y;
    while(x->dir()>=0){
        y=x->p; if(y->p) y->p->push(); y->push(); x->push();
        if(y->dir()>=0) y->dir()==x->dir()? y->rot(): x->rot();
        x->rot();
    }
    x->push(); x->pull();
}
void access(sp x){
    for(sp y=x,last=nullptr;y;y=y->p){
        splay(y);
        y->c[1]=last; last=y;
    }
    splay(x);
}
void evert(sp x){
    access(x); x->flip^=1;
}
sp lca(sp x,sp y){
    if(x==y) return x;
    access(x); access(y);
    if(!x->p) return nullptr;
    splay(x);
    return x->p?:x;
}
void link(sp x,sp y){
    evert(x); x->p=y;
}
void cut(sp x){
    access(x);
    x->c[0]->p=nullptr; x->c[0]=nullptr; x->pull();
}
sp lct[N];
int n,m,q,a,b,c,d,pre,ans[N];
pii edge[N];
void ins(int x){
    tie(a,b)=edge[x];
    if(lca(lct[a],lct[b])){
        evert(lct[b]); access(lct[a]); int y=Mi(lct[a]); tie(c,d)=edge[y];
        if(Sz(lct[a])%4==1) pre=max(pre,y);
        evert(lct[c]); cut(lct[d]); cut(lct[y]);
    }
    link(lct[x],lct[a]); link(lct[x],lct[b]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("joker.i059", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>q;
    fori(1,n+m*2+1) lct[i]=new node(i);
    fori(1,m+1){
        cin>>a>>b; a+=2*m; b+=2*m; edge[i]=edge[i+m]=pii(a,b);
        ins(i); ans[i+m]=pre+m;
    }
    ans[m]=pre;
    fori(m+1,m*2+1){
        if(ans[i]>m) break;
        ins(i); ans[i]=pre;
    }
    fori(0,q){
        cin>>a>>b; a+=m;
        cout<<(b<ans[a-1]? "YES": "NO")<<nl;
    }
    return 0;
}
/**
lct with rollback?
*/

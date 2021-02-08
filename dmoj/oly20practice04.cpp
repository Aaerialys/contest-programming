#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i++)
#define ford(i,a,b) for(__typeof(a) i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1> using ordered_set=tree<T1,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1,typename T2> using hashmap=gp_hash_table<T1,T2>;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(int x) const { return x ^ SEED; }};

const int N=P2(18),M=1e9+7;
struct node{
    ll l,r,v,lz;
};
class segtree{
    public:
    node seg[2*N];
    segtree(){
        build(1,N,1);
    }
    void build(int l,int r,int num){
        seg[num].l=l; seg[num].r=r;
        if(l==r) return;
        int mid=(l+r)/2;
        build(l,mid,num*2); build(mid+1,r,num*2+1);
    }
    void pushdown(int num){
        if(seg[num].lz==inf) return;
        seg[num].v=seg[num].lz;
        if(seg[num].l!=seg[num].r){
            seg[num*2].lz=seg[num*2+1].lz=seg[num].lz;
        }
        seg[num].lz=inf;
    }
    void update(int pos,int v,int num){
        pushdown(num);
        if(seg[num].l==pos&&seg[num].r==pos){
            seg[num].v=max(seg[num].v,0LL+v);
            return;
        }
        pushdown(num*2); pushdown(num*2+1);
        int mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid) update(pos,v,num*2);
        else update(pos,v,num*2+1);
        seg[num].v=max(seg[num*2].v,seg[num*2+1].v);
    }
    void clear(){
        seg[1].lz=-inf;
    }
    ll query(int l,int r){
        if(r<0) return -inf;
        if(r==0) return seg[0].v;
        if(l<1) return max(seg[0].v,query(1,r,1));
        return query(l,r,1);
    }
    ll query(int l,int r,int num){
        pushdown(num);
        if(seg[num].l==l&&seg[num].r==r) return seg[num].v;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid) return query(l,r,num*2);
        if(l>mid) return query(l,r,num*2+1);
        return max(query(l,mid,num*2),query(mid+1,r,num*2+1));
    }
};
segtree st,stt;
ll n,m,L,R,a,b,c,sz[N],tot,ans,last,val[N];
vector<pll> gr[N],temp,temp2;
bool block[N];

void szdfs(int v,int p){
    sz[v]=1;
    for(auto i:gr[v]) if(i.ps!=p&&!block[i.ps]){
            szdfs(i.ps,v);
            sz[v]+=sz[i.ps];
        }
}
int getcentroid(int v,int p){
    for(auto i:gr[v]) if(i.ps!=p&&!block[i.ps]&&sz[i.ps]*2>tot) return getcentroid(i.ps,v);
    return v;
}
void dfs(int v,int p,int d,int c,int cd){
    temp2.pb({d,cd}); ans=max(ans,cd+st.query(L-d,R-d),cd-tot+stt.query(L-d,R-d));
    for(auto i:gr[v]) if(i.ps!=p&&!block[i.ps]){
        dfs(i.ps,v,d+1,i.pf,i.pf==c? cd:cd+val[i.pf]);
    }
}
void go(int v){
    szdfs(v,-1); tot=sz[v]; v=getcentroid(v,-1); block[v]=true; st.clear(); last=-1; stt.seg[0].v=-inf; temp.clear(); temp2.clear();
    for(auto i:gr[v]) if(!block[i.ps]){
        if(i.pf!=last){
            for(auto j:temp){
                st.update(j.pf,j.ps,1);
            }
            stt.clear(); temp.clear(); last=i.pf;
        }
        tot=val[i.pf]; dfs(i.ps,v,1,i.pf,val[i.pf]);
        for(auto j:temp2){
            temp.pb(j); stt.update(j.pf,j.ps,1);
        }
        temp2.clear();
    }
    for(auto i:gr[v]) if(!block[i.ps]) go(i.ps);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>L>>R; ans=-INF;
    fori(1,m+1) cin>>val[i];
    fori(1,n){
        cin>>a>>b>>c;
        gr[a].pb({c,b}); gr[b].pb({c,a});
    }
    fori(1,n+1) sort(all(gr[i]));
    go(1);
    cout<<ans;
    return 0;
}
/**

*/
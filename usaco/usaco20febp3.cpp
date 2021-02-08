#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define hashmap gp_hash_table
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
#define popcount __builtin_popcount
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define pow2(x) (1LL<<(x))
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef long long ui128;
#endif
typedef long long ll; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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

const int N=1<<18,M=1e9+7,NK=11;
ll n,K,C[NK][NK],ans,temp[NK],x;
pii seg[N];
struct node{
    int l,r;
    ll v,lz;
};
class segtree{
    public:
    node seg[2*N];
    segtree(){
        build(1,N,1);
    }
    void build(int l,int r,int num){
        seg[num].l=l; seg[num].r=r; seg[num].lz=1;
        if(l==r){
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,num*2); build(mid+1,r,num*2+1);
    }
    void pushdown(int num){
        if(seg[num].lz==1) return;
        seg[num].v=seg[num].v*seg[num].lz%M;
        if(seg[num].l!=seg[num].r){
            seg[2*num].lz=seg[2*num].lz*seg[num].lz%M;
            seg[2*num+1].lz=seg[2*num+1].lz*seg[num].lz%M;
        }
        seg[num].lz=1;
    }
    void update(int pos,int v,int num){
        if(num==1)
            pushdown(num);
        if(seg[num].l==seg[num].r){
            seg[num].v=v;
            return;
        }
        pushdown(2*num); pushdown(2*num+1);
        int mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid)
            update(pos,v,num*2);
        else
            update(pos,v,num*2+1);
        seg[num].v=(seg[num*2].v+seg[num*2+1].v)%M;
    }
    void updateR(int l,int r,int v,int num){
        if(num==1)
            pushdown(num);
        if(seg[num].l==l&&seg[num].r==r){
            seg[num].lz=seg[num].lz*v%M;
            pushdown(num);
            return;
        }
        pushdown(num*2); pushdown(num*2+1);
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            updateR(l,r,v,num*2);
        else if(l>mid)
            updateR(l,r,v,num*2+1);
        else{
            updateR(l,mid,v,num*2); updateR(mid+1,r,v,num*2+1);
        }
        seg[num].v=(seg[num*2].v+seg[num*2+1].v)%M;
    }
    int query(int l,int r,int num){
        pushdown(num);
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,num*2);
        if(l>mid)
            return query(l,r,num*2+1);
        return (query(l,mid,num*2)+query(mid+1,r,num*2+1))%M;
    }
};
segtree st[NK];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    fori(0,NK){
        C[i][0]=1;
        forj(1,i+1)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    cin>>n>>K; st[0].update(1,1,1);
    fori(0,n){
        cin>>seg[i].pf>>seg[i].ps; seg[i].pf++; seg[i].ps++;
    }
    sort(seg,seg+n);
    for(auto cur:seg){
        if(n--==0) break;
        forj(0,K+1){
            temp[j]=st[j].query(1,cur.pf-1,1); x=st[j].query(cur.ps,cur.ps,1);
            fork(0,j+1)
                x+=temp[k]*C[j][k];
            st[j].update(cur.ps,(st[j].query(cur.pf,cur.ps,1)+x)%M,1);
            st[j].updateR(cur.ps+1,N-1,2,1);
        }
    }
    cout<<st[K].query(1,N-1,1);
    return 0;
}
/**

*/
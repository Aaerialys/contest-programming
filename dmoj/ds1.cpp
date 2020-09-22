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

const int N=P2(17),M=1e9+7; //N=power of 2
struct node{
    ll v;
};
class segTree{ // 0 indexed
public:
    node seg[2*N];
    node merge(node l,node r){
        node ret; ret.v=l.v+r.v;
        return ret;
    }
    void pull(int num){
        seg[num]=merge(seg[num*2],seg[num*2+1]);
    }
    void build(int *arr){
        fori(0,N) seg[i+N].v=arr[i];
        ford(i,N-1,1) pull(i);
    }
    void upd(int pos,int val){
        seg[pos+=N].v=val;
        for(pos/=2;pos;pos/=2) pull(pos);
    }
    ll query(int l,int r){
        node ret1,ret2; ret1.v=ret2.v=0;
        for(l+=N,r+=N+1;l<r;l/=2,r/=2){
            if(l&1) ret1=merge(ret1,seg[l++]);
            if(r&1) ret2=merge(seg[--r],ret2);
        }
        return merge(ret1,ret2).v;
    }
};
segTree st1,st2;
int n,q,arr[N],f[N],a,b;
char ch;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(0,n){
        cin>>arr[i]; f[arr[i]]++;
    }
    st1.build(arr); st2.build(f);
    fori(0,q){
        cin>>ch;
        if(ch=='C'){
            cin>>a>>b; a--;
            st1.upd(a,b);
            st2.upd(arr[a],--f[arr[a]]); arr[a]=b;
            st2.upd(arr[a],++f[arr[a]]);
        }
        if(ch=='S'){
            cin>>a>>b;
            cout<<st1.query(a-1,b-1)<<"\n";;
        }
        if(ch=='Q'){
            cin>>a;
            cout<<st2.query(0,a)<<"\n";
        }
    }
    return 0;
}
/**

*/
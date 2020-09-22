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

const int N=P2(21),M=MOD;

int n,q,in[N],sz[N],rt[N],par[N],a,b,loc[N],last[N],cur;
string s;
vector<int> gr[N],res;
struct AC{
    struct node{
        int to[26]={0};
        int link;
    };
    int sz;
    node ac[N];
    AC(){
        sz++;
    }
    void add(string s){
        int cur=0;
        for(auto ch:s){
            if(!ac[cur].to[ch-'a']){
                ac[cur].to[ch-'a']=sz;
                sz++;
            }
            cur=ac[cur].to[ch-'a'];
        }
        loc[++a]=cur;
    }
    void init(){
        int v,u; queue<int> toV; toV.push(0); ac[0].link=-1;
        while(sz(toV)){
            v=toV.front(); toV.pop();
            if(ac[v].link!=-1) gr[ac[v].link].pb(v);
            fori(0,26) if(ac[v].to[i]){
                int x=ac[v].to[i];
                u=ac[v].link;
                while(u!=-1&&!ac[u].to[i]) u=ac[u].link;
                ac[x].link=u==-1? 0: ac[u].to[i];
                toV.push(x);
            }
        }
    }
} ac;
struct BITree{
    int bit[N];
    void upd(int x,int v){
        for(x+=2;x<N;x+=x&-x) bit[x]+=v;
    }
    int query(int x){
        int ret=0;
        for(x+=2;x;x-=x&-x) ret+=bit[x];
        return ret;
    }
    void upd(int l,int r,int v){
        upd(l,1); upd(r+1,-1);
    }
} bit;
int szDfs(int v){
    sz[v]=1;
    for(auto& i:gr[v]){
        par[i]=v; sz[v]+=szDfs(i);
        if(sz[i]>sz[gr[v][0]]) swap(i,gr[v][0]);
    }
    return sz[v];
}
void hldDfs(int v){
    in[v]=a++;
    for(auto i:gr[v]){
        rt[i]=(i==gr[v][0]? rt[v]: i);
        hldDfs(i);
    }
}
void updPath(int u,int v){
    while(rt[u]!=rt[v]){
        if(in[rt[u]]>in[rt[v]]) swap(u,v);
        if(in[v]>last[rt[v]]){
            bit.upd(last[rt[v]]+1,in[v],1);
            last[rt[v]]=in[v]; res.pb(rt[v]);
        }
        v=par[rt[v]];
    }
    if(in[u]>in[v]) swap(u,v);
    if(in[v]>last[rt[v]]){
        bit.upd(max(last[rt[v]]+1,in[u]),in[v],1); //u for nodes, gr[u][0] for edges and return if u==v
        last[rt[v]]=in[v]; res.pb(rt[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("divljak.in.6a", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n){
        cin>>s; ac.add(s);
    }
    a=0; ac.init();
    szDfs(0); hldDfs(0); par[0]=-1;
    fori(0,N) last[i]=in[i]-1;
    cin>>q;
    fori(0,q){
        cin>>a;
        if(a==1){
            cin>>s; cur=0;
            for(auto j:s){
                while(cur!=-1&&!ac.ac[cur].to[j-'a']) cur=par[cur];
                if(cur==-1) cur=0;
                else cur=ac.ac[cur].to[j-'a'];
                updPath(0,cur);
            }
            for(auto j:res) last[j]=in[j]-1;
            res.clear();
        }
        else if(a==2){
            cin>>b;
            cout<<bit.query(in[loc[b]])<<nl;
        }
    }
    return 0;
}
/**
5
abba
bbaa
b
a
ba
6
1 aaabbabbaab
1 baabaaa
1 aabbbab
2 3
1 aaaaa
2 3
*/
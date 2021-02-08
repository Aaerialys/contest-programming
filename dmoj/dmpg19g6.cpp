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
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};
#define nl "\n"

const int N=400010,M=MOD;

ll n;
i128 sz[N],a,b,dif[N],t;
bool vis[N];
string s;
struct node{
    int len,p,nxt[26];
};
struct SuffixAutomaton{
    int last;
    vector<node> st;
    void init(string s){
        st.clear(); last=0; st.emplace_back(); st[0].p=-1;
        for(auto i:s) ins(i-'a');
    }
    void ins(int c){
        int cur=st.size(),p=last; st.emplace_back(); sz[cur]=1;
        st[cur].len=st[last].len+1;
        while(p!=-1&&!st[p].nxt[c]){
            st[p].nxt[c]=cur;
            p=st[p].p;
        }
        if(p==-1) st[cur].p=0;
        else{
            int q=st[p].nxt[c];
            if(st[q].len==st[p].len+1) st[cur].p=q;
            else{
                int clone=st.size(); st.pb(st[q]);
                st[clone].len=st[p].len+1;
                while(p!=-1&&st[p].nxt[c]==q){
                    st[p].nxt[c]=clone;
                    p=st[p].p;
                }
                st[q].p=st[cur].p=clone;
            }
        }
        last=cur;
    }
};
SuffixAutomaton sa;
vector<int> gr[N];
int szdfs(int v){
    for(auto i:gr[v]) sz[v]+=szdfs(i);
    return sz[v];
}
void dfs(int v){
    i128 len=sa.st[v].len,plen=v? sa.st[sa.st[v].p].len:-1,x=0; vis[v]=1;
    fori(0,26) if(sa.st[v].nxt[i]){
        if(!vis[sa.st[v].nxt[i]]) dfs(sa.st[v].nxt[i]);
        sz[v]+=sz[sa.st[v].nxt[i]];
        x-=sz[sa.st[v].nxt[i]]*sz[sa.st[v].nxt[i]];
    }
    x+=sz[v]*sz[v];
    dif[plen+1]+=x;
    dif[len+1]-=x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>s; n=sz(s);
    sa.init(s);
    fori(1,sz(sa.st)) gr[sa.st[i].p].pb(i);
    szdfs(0);
    sz[0]=0; dfs(0); t=n*(n+1)/2; t=t*t;
    fori(1,n+1) dif[i]+=dif[i-1],t-=dif[i];
    cout<<int(t%M)<<nl;
    fori(1,n+1) cout<<int(dif[i]%M)<<nl;
    return 0;
}
/**
4 2 1 2 1
4 4 3 2 1

boai
90
4
1
4
1

abcd
70
16
9
4
1
*/
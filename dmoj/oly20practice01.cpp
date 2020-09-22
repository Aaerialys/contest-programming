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

const int N=200010,M=MOD;
struct node{
    int len,p,nxt[27],mlen,id;
};
vector<node> sa;
struct SuffixAutomaton{
    int last,snum;
    void init(string s){
        if(!sz(sa)) sa.eb(),sa[0].p=-1;
        ins(26,0,++snum);
        fori(0,sz(s)) ins(s[i]-'a',i+1,snum);
    }
    void ins(int c,int pos,int id){
        int cur=sz(sa),p=last; sa.eb();
        sa[cur].len=sa[last].len+1; sa[cur].mlen=pos; sa[cur].id=id;
        while(p!=-1&&!sa[p].nxt[c]){
            sa[p].nxt[c]=cur;
            p=sa[p].p;
        }
        if(p==-1) sa[cur].p=0;
        else{
            int q=sa[p].nxt[c];
            if(sa[q].len==sa[p].len+1) sa[cur].p=q;
            else{
                int clone=sz(sa); sa.pb(sa[q]);
                sa[clone].len=sa[p].len+1;
                while(p!=-1&&sa[p].nxt[c]==q){
                    sa[p].nxt[c]=clone;
                    p=sa[p].p;
                }
                sa[q].p=sa[cur].p=clone;
            }
        }
        last=cur;
    }
};
SuffixAutomaton SA;
ll n,a,b,ans[N];
vector<int> gr[N];
string in;
void dfs(int v){
    sa[v].len=min(sa[v].len,sa[v].mlen);
    for(auto i:gr[v]){
        dfs(i);
        if(sa[v].id&&sa[i].id!=sa[v].id) sa[v].id=-1;
        else sa[v].id=sa[i].id;
    }
    if(v==4){
        auto temp=sa[v];
        temp.id^=0;
    }
    if(v&&sa[v].id>0) ans[sa[v].id]+=sa[v].len-sa[sa[v].p].len;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n){
        cin>>in; SA.init(in);
    }
    fori(1,sz(sa)) gr[sa[i].p].pb(i);
    dfs(0);
    fori(1,n+1) cout<<ans[i]<<nl;
    return 0;
}
/**
concatenate all strings, make suffix automaton, ignore trans-string substring
node with children from 2 strings don't count
*abc*aabbcc*aaaabbb*cba

aaaa

*/
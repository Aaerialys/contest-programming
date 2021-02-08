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
//inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(int x) const { return x ^ SEED; }};

const int N=100010,root=3,M=(119<<23)+1; // 998244353
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%M*a%M; return t*t%M;}
typedef complex<double> cd;
template<class T> void fft(vector<T>& a,const vector<T>& rt,bool inv=0){
	int n=sz(a);
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n>>1; for (; j&bit; bit /= 2) j ^= bit;
		j ^= bit; if (i < j) swap(a[i],a[j]);
	} // sort #s from 0 to n-1 by reverse binary
	for (ll len = 1; len < n; len *= 2)
		for (ll i = 0; i < n; i += 2*len) forj(0,len) {
			T u = a[i+j], v = a[i+j+len]*rt[n/2/len*j];
			a[i+j] = (u+v), a[i+j+len] = (u-v);
		}
	if(inv){
		reverse(1+all(a));
		T i = (T)1/(T)n;
		for(auto& x:a) x=x*i;
	}
}
template<class T> vector<T> fmul(vector<T> a, vector<T> b) {
	if(!sz(a)||!sz(b)) return {};
	int s = sz(a)+sz(b)-1, n = 1<<(32-clz(s-1)); a.resize(n); b.resize(n);
	vector<cd> rt,aa,bb; double ang=2*3.14159265358979/n;
	fori(0,n) rt.pb(cd(cos(ang*i),sin(ang*i)));
	for(auto i:a) aa.pb(cd(i));
	for(auto i:b) bb.pb(cd(i));
	fft(aa,rt); fft(bb,rt);
	fori(0,n) aa[i]=aa[i]*bb[i];
	fft(aa,rt,1);
	a.clear();
	for(auto i:aa) a.pb(round(i.real()));
	return a;
}
int n,q,sz[N],a,b,tot;
ll ans[N];
bool done[N],val[N];
vector<int> gr[N];
vector<ll> temp,temp2,temp3;
int szdfs(int v,int p){
    sz[v]=1;
    for(auto i:gr[v]) if(i!=p&&!done[i]) sz[v]+=szdfs(i,v);
    return sz[v];
}
int getcentroid(int v,int p){
    for(auto i:gr[v]) if(i!=p&&!done[i]&&sz[i]*2>tot) return getcentroid(i,v);
    return v;
}
void dfs(int v,int p,int d){
    d+=val[v]; temp2[d]++;
    for(auto i:gr[v]) if(i!=p&&!done[i]) dfs(i,v,d);
}
void go(int v){
    tot=szdfs(v,-1); v=getcentroid(v,-1); szdfs(v,-1); done[v]=true; temp.clear(); temp.pb(1); tot=0;
    sort(all(gr[v]),[&](int a,int b){return sz[a]<sz[b];});
    for(auto i:gr[v]) if(!done[i]){
        temp2.clear(); temp2.resize(sz[i]+1);
        dfs(i,v,0);
        temp3=fmul(temp,temp2);
        forj(0,sz(temp3)) ans[j+val[v]]+=temp3[j];
        tot=max(tot,sz[i]); temp.resize(tot+1);
        forj(0,sz(temp2)) temp[j]+=temp2[j];
    }
    for(auto i:gr[v]) if(!done[i]) go(i);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(1,n+1) cin>>val[i];
    fori(1,n){
        cin>>a>>b;
        gr[a].pb(b); gr[b].pb(a);
    }
    go(1);
    fori(1,n+1) ans[i]+=ans[i-1];
    cin>>q;
    fori(0,q){
        cin>>a>>b;
        cout<<ans[b]-(a? ans[a-1]:0)<<"\n";
    }
    return 0;
}
/**

*/
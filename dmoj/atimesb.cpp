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
#define popcountll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
    typedef long long i128; typedef unsigned long long ui128;
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
template<typename T1,typename T2> using hashmap=gp_hash_table<T1,T2>;
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};


const int root=3,M=(119<<23)+1; // 998244353
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%M*a%M; return t*t%M;}
template<class T> void fft(vector<T>& a,const vector<T>& rt,bool inv=0){
	int n=sz(a);
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n>>1; for (; j&bit; bit /= 2) j ^= bit;
		j ^= bit; if (i < j) swap(a[i],a[j]);
	} // sort #s from 0 to n-1 by reverse binary
	for (ll len = 1; len < n; len *= 2)
		for (ll i = 0; i < n; i += 2*len) forj(0,len) {
			T u = a[i+j], v = a[i+j+len]*rt[n/2/len*j]%M;
			a[i+j] = (u+v)%M, a[i+j+len] = (u-v+M)%M;
		}
	if(inv){
		reverse(1+all(a));
		T i = fpow(n,M-2);
		for(auto& x:a) x=x*i%M;
	}
}
template<class T> vector<T> fmul(vector<T> a, vector<T> b) {
	if(!sz(a)||!sz(b)) return {};
	int s = sz(a)+sz(b)-1, n = 1<<(32-clz(s-1)); a.resize(n); b.resize(n);
	vector<T> rt={1}; int r=fpow(root,(M-1)/n);
	fori(0,n-1) rt.pb(rt[i]*r%M);
	fft(a,rt); fft(b,rt);
	fori(0,n) a[i]=a[i]*b[i]%M;
	fft(a,rt,1); a.resize(s);
	return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    string s1,s2;
    vector<ll> a,b,c,ans;
    ll x=0;
    cin>>s1>>s2;
    if(s1=="0"||s2=="0"){
        cout<<0;
        return 0;
    }
    for(auto i:s1) a.pb(i-'0');
    for(auto i:s2) b.pb(i-'0');
    c=fmul(a,b); reverse(all(c));
    for(auto i:c){
        x+=i; ans.pb(x%10);
        x/=10;
    }
    while(x){
        ans.pb(x%10); x/=10;
    }
    reverse(all(ans));
    for(auto i:ans) cout<<i;
    return 0;
}
/**

*/
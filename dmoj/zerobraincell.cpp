#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,fma,mmx,popcnt,tune=native" //#pragma GCC optimize "prefetch-loop-arrays"
using namespace std; using namespace __gnu_pbds;
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
#define em emplace
#define mp make_pair
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
    typedef int64_t i128; typedef uint64_t ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld; typedef string str;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<class T1,class T2> using ordered_map=tree<T1,T2,less<T1>,rb_tree_tag,tree_order_statistics_node_update>; template<class T1> using ordered_set=ordered_map<T1,null_type>;
template<class T> using minpq=std::priority_queue<T,vector<T>,greater<T>>; template<class T> using maxpq=std::priority_queue<T,vector<T>,less<T>>;
template<class T> using minpairingheap=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>; template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,less<T>,pairing_heap_tag>;
const int inf=0x3f3f3f3f,MOD=998244353; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
const ll SEED=443214^chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll fpow(ll a,ll b){ll ret=1;for(;b;b>>=1){if(b&1) ret=ret*a%MOD;a=a*a%MOD;}return ret;}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
template<class T1,class T2>constexpr const bool ckmin(T1&x,const T2&y){return x>y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmin(T&x,const Ts&...xs){return ckmin(x,_min(xs...));}
template<class T1,class T2>constexpr const bool ckmax(T1&x,const T2&y){return x<y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmax(T&x,const Ts&...xs){return ckmax(x,_max(xs...));}
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}};
void fileIn(string s){freopen(s.c_str(),"r",stdin);} void fileOut(string s){freopen(s.c_str(),"w",stdout);} void fileIO(string s){fileIn(s+".in"); fileOut(s+".out");}
string to_string(char c){return string(1,c);} string to_string(char* s){return (string)s;} string to_string(string s){return s;}
template<class T> string to_string(complex<T> c){stringstream ss; ss<<c; return ss.str();} template<class T1,class T2> string to_string(pair<T1,T2> p){return "("+to_string(p.pf)+","+to_string(p.ps)+")";}
template<size_t SZ> string to_string(bitset<SZ> b){string ret=""; fori(0,SZ) ret+=char('0'+b[i]); return ret;}
template<class T> string to_string(T v){string ret="{"; for(const auto& x:v) ret+=to_string(x)+","; return ret+"}";}
void DBG(){cerr<<"]"<<endl;} template<class T,class... Ts> void DBG(T x,Ts... xs){cerr<<to_string(x); if(sizeof...(xs)) cerr<<", "; DBG(xs...);}
#ifdef LOCAL_PROJECT
    #define dbg(...) cerr<<"Line("<< __LINE__<<") -> ["<<#__VA_ARGS__<<"]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
#define nl "\n"

const ll N=0,M=MOD,ROOT=3;
int n,B,x;
vector<ll> a,b,rt;

template<class T> void fft(vector<T>& a,bool inv=0){
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
void fft2(vector<ll> &a){
    vector<ll> ret; ret.resize(sz(a));
    fori(0,sz(a)) forj(0,sz(a)) ret[i]=(ret[i]+a[j]*rt[i*j%n])%M;
    swap(ret,a);
}
vector<ll> fwt(vector<ll> x){
    int n=sz(x);
    vector<ll> a[2]; a[0].resize(n); a[1].resize(n);
    fori(0,n) a[1][i]=x[i];
    for(int i=1;i<=n/B;i*=B){
        swap(a[0],a[1]);
        for(int j=0;j<n;j+=i*B){
            fork(0,i){
                vector<ll> temp; int cnt=0;
                for(int ii=j+k;ii<j+i*B;ii+=i) temp.pb(a[0][ii]);
                fft(temp);
                for(int ii=j+k;ii<j+i*B;ii+=i) a[1][ii]=temp[cnt++];
            }
        }
    }
    return a[1];
}
vector<ll> ifwt(vector<ll> x){
    int n=sz(x);
    vector<ll> a[2]; a[0].resize(n); a[1].resize(n);
    fori(0,n) a[1][i]=x[i];
    for(int i=1;i<=n/B;i*=B){
        swap(a[0],a[1]);
        for(int j=0;j<n;j+=i*B){
            fork(0,i){
                vector<ll> temp; int cnt=0;
                for(int ii=j+k;ii<j+i*B;ii+=i) temp.pb(a[0][ii]);
                fft(temp,1);
                for(int ii=j+k;ii<j+i*B;ii+=i) a[1][ii]=temp[cnt++];
            }
        }
    }
    return a[1];
}

ll xb(ll a,ll b){
    ll c=0,p=1;
    while(a||b){
        c+=(a+b)%B*p;
        a/=B; b/=B; p*=B;
    }
    return c;
}
ll xb(ll a,ll b,ll c){
    return xb(a,xb(b,c));
}
vector<ll> conv(vector<ll> A,vector<ll> B){
    vector<ll> a(A),b(B);
    a=fwt(a); b=fwt(b);
    fori(0,n) a[i]=a[i]*b[i]%M;
    a=ifwt(a);
    return a;
}
vector<ll> solve1(vector<ll> a){
    /*cin>>B>>n; a.resize(n); b.resize(n);
    fori(0,n) cin>>a[i];
    fori(0,n) cin>>b[i];//*/
    vector<ll> b,c;
    x=fpow(3,(M-1)/B); rt={1};
    fori(0,B-1) rt.pb(rt[i]*x%M);
    b=conv(a,a); b=conv(b,a);
    fori(0,n) b[xb(i,i,i)]=(b[xb(i,i,i)]+M-a[i]*a[i]%M*a[i]%M)%M;
    c.resize(n);
    fori(0,n) c[xb(i,i)]=(c[xb(i,i)]+a[i]*a[i])%M;
    c=conv(a,c);
    fori(0,n) c[xb(i,i,i)]=(c[xb(i,i,i)]+M-a[i]*a[i]%M*a[i]%M)%M;
    fori(0,n) b[i]=(b[i]+M-c[i]*3%M)*166374059%M;
    return b;
}

vector<ll> solve2(vector<ll> a){
    vector<ll> ret; ret.resize(n);
    fori(0,n) forj(0,i) fork(0,j) ret[xb(i,j,k)]=(ret[xb(i,j,k)]+a[i]*a[j]%M*a[k]%M)%M;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<ll> a;
    cin>>B>>n; a.resize(n);
    fori(0,n) cin>>a[i];
    a=solve1(a);
    fori(0,n) cout<<a[i]<<" ";
    return 0;
    fori(0,5){
        vector<ll> a,b,c;
        B=P2(6); n=P2(18);
        fori(0,n) a.pb(randint(0,1e9));
        fileOut("in3-"+to_string(i+1)+".txt");
        cout<<B<<" "<<n<<nl;
        fori(0,n) cout<<a[i]<<" ";
        cout.flush();
        //cin>>B>>n; a.resize(n);
        //fori(0,n) cin>>a[i];
        b=solve1(a);
        //c=solve2(a); fori(0,n) assert(b[i]==c[i]);
        fileOut("out3-"+to_string(i+1)+".txt");
        fori(0,n) cout<<b[i]<<" ";
        cout.flush();
    }
    return 0;
}

/**

2 4
2 3 5 7



105 70 42 30


4410


base 1024 32 4 2

2 2
1 2
3 4

1 2

1 1
1 -1

3 -1
7 -1

21 1

11 10


(n/B)(B^2)log_b(n) =
vs
(n/B)(BlogB) log_b(n) =

nBlog_B(n)
Nlog(n)*(fft constant)
*/
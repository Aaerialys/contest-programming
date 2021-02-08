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
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};

constexpr i128 base = 1000000000000000000;
constexpr i128 base_digits = 18;

struct bigint {
	// value == 0 is represented by empty z
	vector<i128> z; // digits

	// sign == 1 <==> value >= 0
	// sign == -1 <==> value < 0
	int sign;

	bigint() : sign(1) {}
    bigint(i128 v) { *this = v; }
	bigint &operator=(i128 v) {
		sign = v < 0 ? -1 : 1; v *= sign;
		z.clear(); for (; v > 0; v = v / base) z.push_back((i128) (v % base));
		return *this;
	}

	bigint(const string &s) { read(s); }

	bigint &operator+=(const bigint &other) {
		if (sign == other.sign) {
			for (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {
				if (i == z.size())
					z.push_back(0);
				z[i] += carry + (i < other.z.size() ? other.z[i] : 0);
				carry = z[i] >= base;
				if (carry)
					z[i] -= base;
			}
		} else if (other != 0 /* prevent infinite loop */) {
			*this -= -other;
		}
		return *this;
	}

	friend bigint operator+(bigint a, const bigint &b) { return a += b; }

	bigint &operator-=(const bigint &other) {
		if (sign == other.sign) {
			if (sign == 1 && *this >= other || sign == -1 && *this <= other) {
				for (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {
					z[i] -= carry + (i < other.z.size() ? other.z[i] : 0);
					carry = z[i] < 0;
					if (carry)
						z[i] += base;
				}
				trim();
			} else {
				*this = other - *this;
				this->sign = -this->sign;
			}
		} else {
			*this += -other;
		}
		return *this;
	}

	friend bigint operator-(bigint a, const bigint &b) { return a -= b; }

	bool operator<(const bigint &v) const {
		if (sign != v.sign)
			return sign < v.sign;
		if (z.size() != v.z.size())
			return z.size() * sign < v.z.size() * v.sign;
		for (int i = (int) z.size() - 1; i >= 0; i--)
			if (z[i] != v.z[i])
				return z[i] * sign < v.z[i] * sign;
		return false;
	}

	bool operator>(const bigint &v) const { return v < *this; }
	bool operator<=(const bigint &v) const { return !(v < *this); }
	bool operator>=(const bigint &v) const { return !(*this < v); }

	bool operator==(const bigint &v) const { return !(*this < v) && !(v < *this); }

	bool operator!=(const bigint &v) const { return *this < v || v < *this; }

	void trim() {
		while (!z.empty() && z.back() == 0) z.pop_back();
		if (z.empty()) sign = 1;
	}

	bool isZero() const { return z.empty(); }

	friend bigint operator-(bigint v) {
		if (!v.z.empty()) v.sign = -v.sign;
		return v;
	}

	bigint abs() const {
		return sign == 1 ? *this : -*this;
	}

	void read(const string &s) {
		sign = 1;
		z.clear();
		int pos = 0;
		while (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = (int) s.size() - 1; i >= pos; i -= base_digits) {
			i128 x = 0;
			for (int j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			z.push_back(x);
		}
		trim();
	}

	friend istream &operator>>(istream &stream, bigint &v) {
		string s; stream >> s;
		v.read(s);
		return stream;
	}

	friend ostream &operator<<(ostream &stream, const bigint &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.z.empty() ? 0 : v.z.back());
		for (int i = (int) v.z.size() - 2; i >= 0; --i)
			stream << setw(base_digits) << setfill('0') << v.z[i];
		return stream;
	}

};
bigint a,b;
string s1,s2;
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n){
        cin>>a>>b;
        cout<<a+b<<"\n";
    }
    return 0;
}
/**
1
10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004
40000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000001
*/
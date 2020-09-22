#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i--)
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
using namespace std;
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#endif
typedef long long ll; typedef int8_t byte; typedef long double lld;
typedef pair<ll,ll> pii;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
mt19937 randgen(time(0)); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=1010,M=1e9+9,B=37;

string s1,s2;
ll n,a,b,c,d,p[N]={1},snum1[N],snum2[N];
set<pii> ns;
ll num1(int l,int r)
{
    if(l>r)
        return 0;
    return (snum1[r]-snum1[l-1]*p[r-l+1]%M+M)%M;
}
ll num2(int l,int r)
{
    if(l>r)
        return 0;
    return (snum2[r]-snum2[l-1]*p[r-l+1]%M+M)%M;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    fori(1,N)
        p[i]=p[i-1]*B%M;
    cin>>s1>>s2; s1='.'+s1; s2='.'+s2; n=s1.size();
    forj(1,s1.size())
        snum1[j]=(snum1[j-1]*B%M+s1[j]-'a'+1)%M;
    forj(1,s2.size())
        snum2[j]=(snum2[j-1]*B%M+s2[j]-'a'+1)%M;
    fori(1,n)
    {
        ns.clear();
        forj(i,n)
            ns.insert((pii){(num1(1,j-i)*p[n-j-1]+num1(j+1,n-1))%M,num1(j-i+1,j)});
        forj(i,n)
            if(ns.count((pii){(num2(1,j-i)*p[n-j-1]+num2(j+1,n-1))%M,num2(j-i+1,j)}))
            {
                cout<<"aliens";
                return 0;
            }
    }
    cout<<"no aliens";
    return 0;
}
/**
abcdefg
abcfdeg
44412 3412
44412 1234
*/
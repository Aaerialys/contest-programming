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
typedef pair<int,int> pii;
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

const int N=200010;
deque<int> mh;
ll n,x,y,a,b,h[N],d[N],td;
lld EPS=1.00001;
pii ans[N];
int slope(int aa,int bb,int cc)
{
    i128 s1=1,s2=1;
    s1=s1*(h[aa]-h[bb])*(d[aa]-d[cc]);
    s2=s2*(h[aa]-h[cc])*(d[aa]-d[bb]);
    if(s1==s2)
        return 0;
    if(s1<s2)
        return -1;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n)
        cin>>h[i];
    fori(1,n)
        cin>>d[i];
    fori(1,n)
        d[i]+=d[i-1];
    ans[0].pf=-1; mh.push_back(0);
    fori(1,n)
    {
        while(mh.size()>1&&slope(i,mh[mh.size()-1],mh[mh.size()-2])>=0)
            mh.pop_back();
        ans[i].pf=h[mh.back()];
        if(h[i]>=h[mh[mh.size()-1]])
            mh.pop_back();
        mh.push_back(i);
    }
    mh.clear(); mh.push_back(n-1); ans[n-1].ps=-1;
    ford(i,n-2,0)
    {
        while(mh.size()>1&&slope(i,mh[mh.size()-1],mh[mh.size()-2])<=0)
            mh.pop_back();
        ans[i].ps=h[mh.back()];
        if(h[i]>=h[mh[mh.size()-1]])
            mh.pop_back();
        mh.push_back(i);
    }
    fori(0,n)
        cout<<ans[i].pf<<" "<<ans[i].ps<<"\n";
    return 0;
}
/**
0 1000000000
500000000000 888901111
1400099009991 688901111
1s

111098889/500000000000 = 0.000222197778
200000000/900099009991 = 0.000222197778

99999999999999999999
100000000000000000000
/450049504995500000000000

3
1000000000 888901111 688901111
500000000000 900099009991
*/
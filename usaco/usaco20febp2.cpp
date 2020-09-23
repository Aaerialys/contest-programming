#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
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
#else
    typedef long long i128; typedef long long ui128;
#endif
typedef long long ll; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
mt19937 randgen(time(0)); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=1301;
bool cow[N][N],cow2[N][N];
int n,t,x,y,s;
char ch;

int main(){
    //freopen("2.in","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    forj(0,n)
        fori(0,n){
            cin>>ch; cow[i][j]=(ch=='*');
        }
    fork(1,n+1){
        fori(0,n*2){
            s=0;
            for(x=i+k,y=0;x>i;x--,y++){
                s+=cow[x+k][y]&cow[x][y+k];
            }
            for(x=i,y=0;x>=0;x--,y++){
                if(cow[x][y])
                    t+=s;
                s+=cow[x][y+k*2]&cow[x+k][y+k];
                s-=cow[x+k*2][y]&cow[x+k][y+k];
            }
        }
    }
    fori(0,n) forj(0,n) cow2[n-1-j][i]=cow[i][j];
    fori(0,n) forj(0,n) cow[i][j]=cow2[i][j];
    fork(1,n+1){
        fori(0,n*2){
            s=0;
            for(x=i+k,y=0;x>i;x--,y++){
                s+=cow[x+k][y]&cow[x][y+k];
            }
            for(x=i,y=0;x>=0;x--,y++){
                if(cow[x][y])
                    t+=s;
                s+=cow[x][y+k*2]&cow[x+k][y+k];
                s-=cow[x+k*2][y]&cow[x+k][y+k];
            }
        }
    }
    fori(0,n) forj(0,n) cow2[n-1-j][i]=cow[i][j];
    fori(0,n) forj(0,n) cow[i][j]=cow2[i][j];
    fork(1,n+1){
        fori(0,n*2){
            s=0;
            for(x=i+k,y=0;x>i;x--,y++){
                s+=cow[x+k][y]&cow[x][y+k];
            }
            for(x=i,y=0;x>=0;x--,y++){
                if(cow[x][y])
                    t+=s;
                s+=cow[x][y+k*2]&cow[x+k][y+k];
                s-=cow[x+k*2][y]&cow[x+k][y+k];
            }
        }
    }
    fori(0,n) forj(0,n) cow2[n-1-j][i]=cow[i][j];
    fori(0,n) forj(0,n) cow[i][j]=cow2[i][j];
    fork(1,n+1){
        fori(0,n*2){
            s=0;
            for(x=i+k,y=0;x>i;x--,y++){
                s+=cow[x+k][y]&cow[x][y+k];
            }
            for(x=i,y=0;x>=0;x--,y++){
                if(cow[x][y])
                    t+=s;
                s+=cow[x][y+k*2]&cow[x+k][y+k];
                s-=cow[x+k*2][y]&cow[x+k][y+k];
            }
        }
    }
    cout<<t;
    return 0;
}
/**

a+b+c=c+d+a = b+d
b=d=a+c
3
*.*
.*.
...

.*.
*..
.*.


*..

104712
198398
284166
380669

108841
219138
328643
436237

5
*****
*****
*****
*****
*****
24 vs 22


32
50
54
72



19
38
57
76
*/
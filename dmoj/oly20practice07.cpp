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
#define P2(x) (1LL<<(x))
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

const int N=64;
ll q,M,n,m,T,a,b,c,num[N][2][2][2],sum[N][2][2][2];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>q;
    while(q--){
        cin>>n>>m>>T>>M; seto(num,0); seto(sum,0); num[61][1][1][1]=1;
        ford(i,60,0) foru(s1,0,2) foru(s2,0,2) foru(s3,0,2){
            if(!num[i+1][s1][s2][s3]) continue;
            int x1=n>>i&1,x2=m>>i&1,x3=T>>i&1;
            foru(t1,0,(s1?x1:1)+1) foru(t2,0,(s2?x2:1)+1) if(!s3||(t1^t2)>=x3){
                int p1=s1&&t1==x1,p2=s2&&t2==x2,p3=s3&&(t1^t2==x3);
                num[i][p1][p2][p3]+=num[i+1][s1][s2][s3];
                sum[i][p1][p2][p3]+=sum[i+1][s1][s2][s3];
                if(t1^t2) sum[i][p1][p2][p3]+=P2(i)%M*num[i+1][s1][s2][s3]%M;
                num[i][p1][p2][p3]%=M; sum[i][p1][p2][p3]%=M;
            }
        }
        cout<<(sum[0][0][0][0]-T%M*num[0][0][0][0]%M+M)%M<<"\n";
    }
    return 0;
}
/**

f(n,m)= f(n/2,m/2)
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
1 0 3 2 5 4 7 6 9 8 11 10 13 12 15 14 17 16 19 18 21 20 23 22 25 24 27 26 29 28 31 30
2 3 0 1 6 7 4 5 10 11 8 9 14 15 12 13 18 19 16 17 22 23 20 21 26 27 24 25 30 31 28 29
3 2 1 0 7 6 5 4 11 10 9 8 15 14 13 12 19 18 17 16 23 22 21 20 27 26 25 24 31 30 29 28
4 5 6 7 0 1 2 3 12 13 14 15 8 9 10 11 20 21 22 23 16 17 18 19 28 29 30 31 24 25 26 27
5 4 7 6 1 0 3 2 13 12 15 14 9 8 11 10 21 20 23 22 17 16 19 18 29 28 31 30 25 24 27 26
6 7 4 5 2 3 0 1 14 15 12 13 10 11 8 9 22 23 20 21 18 19 16 17 30 31 28 29 26 27 24 25
7 6 5 4 3 2 1 0 15 14 13 12 11 10 9 8 23 22 21 20 19 18 17 16 31 30 29 28 27 26 25 24
8 9 10 11 12 13 14 15 0 1 2 3 4 5 6 7 24 25 26 27 28 29 30 31 16 17 18 19 20 21 22 23
9 8 11 10 13 12 15 14 1 0 3 2 5 4 7 6 25 24 27 26 29 28 31 30 17 16 19 18 21 20 23 22
10 11 8 9 14 15 12 13 2 3 0 1 6 7 4 5 26 27 24 25 30 31 28 29 18 19 16 17 22 23 20 21
11 10 9 8 15 14 13 12 3 2 1 0 7 6 5 4 27 26 25 24 31 30 29 28 19 18 17 16 23 22 21 20
12 13 14 15 8 9 10 11 4 5 6 7 0 1 2 3 28 29 30 31 24 25 26 27 20 21 22 23 16 17 18 19
13 12 15 14 9 8 11 10 5 4 7 6 1 0 3 2 29 28 31 30 25 24 27 26 21 20 23 22 17 16 19 18
14 15 12 13 10 11 8 9 6 7 4 5 2 3 0 1 30 31 28 29 26 27 24 25 22 23 20 21 18 19 16 17
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16
16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
17 16 19 18 21 20 23 22 25 24 27 26 29 28 31 30 1 0 3 2 5 4 7 6 9 8 11 10 13 12 15 14
18 19 16 17 22 23 20 21 26 27 24 25 30 31 28 29 2 3 0 1 6 7 4 5 10 11 8 9 14 15 12 13
19 18 17 16 23 22 21 20 27 26 25 24 31 30 29 28 3 2 1 0 7 6 5 4 11 10 9 8 15 14 13 12
20 21 22 23 16 17 18 19 28 29 30 31 24 25 26 27 4 5 6 7 0 1 2 3 12 13 14 15 8 9 10 11
21 20 23 22 17 16 19 18 29 28 31 30 25 24 27 26 5 4 7 6 1 0 3 2 13 12 15 14 9 8 11 10
22 23 20 21 18 19 16 17 30 31 28 29 26 27 24 25 6 7 4 5 2 3 0 1 14 15 12 13 10 11 8 9
23 22 21 20 19 18 17 16 31 30 29 28 27 26 25 24 7 6 5 4 3 2 1 0 15 14 13 12 11 10 9 8
24 25 26 27 28 29 30 31 16 17 18 19 20 21 22 23 8 9 10 11 12 13 14 15 0 1 2 3 4 5 6 7
25 24 27 26 29 28 31 30 17 16 19 18 21 20 23 22 9 8 11 10 13 12 15 14 1 0 3 2 5 4 7 6
26 27 24 25 30 31 28 29 18 19 16 17 22 23 20 21 10 11 8 9 14 15 12 13 2 3 0 1 6 7 4 5
27 26 25 24 31 30 29 28 19 18 17 16 23 22 21 20 11 10 9 8 15 14 13 12 3 2 1 0 7 6 5 4
28 29 30 31 24 25 26 27 20 21 22 23 16 17 18 19 12 13 14 15 8 9 10 11 4 5 6 7 0 1 2 3
29 28 31 30 25 24 27 26 21 20 23 22 17 16 19 18 13 12 15 14 9 8 11 10 5 4 7 6 1 0 3 2
30 31 28 29 26 27 24 25 22 23 20 21 18 19 16 17 14 15 12 13 10 11 8 9 6 7 4 5 2 3 0 1
31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
*/
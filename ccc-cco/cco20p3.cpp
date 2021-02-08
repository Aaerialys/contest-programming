#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,fma,mmx,popcnt,tune=native" 
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
struct chash{ll operator()(ll x) const{x+=SEED+0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}};
#define nl "\n"

const int N=500010,B=19,M=MOD;
int n,m,x,y,z,dep[N],up[N],uc[N][4],dc[N][3],di[N],p[B][N],pp[B][N],db[B][N],si[B][N],sd[B][N],ans,a,b,c,d,px,py,bx,by,down[N],mdd[N];
vector<int> gr[N];
vector<tuple<int,int,int>> e;
void dfs(int v,int par=0){
    p[0][v]=par; pp[0][v]=v;
    for(auto i:gr[v]) if(i!=par){
        dep[i]=dep[v]+1;
        dfs(i,v);
        di[v]=max(di[v],di[i],up[v]+up[i]+1);
        up[v]=max(up[v],up[i]+1);
        x=i;
        forj(0,4) if(up[uc[v][j]]<up[x]+1) swap(uc[v][j],x);
        x=i;
        forj(0,3) if(di[dc[v][j]]<di[x]) swap(dc[v][j],x);
    }
}
void dfs2(int v,int par=0){
    b=down[v]; a=mdd[v]; c=d=0;
    for(auto i:gr[v]) if(i!=par){
        if(up[i]+1>b){
            d=c; c=i;
            a=b+up[i]+1;
            b=up[i]+1;
        }
        if(di[i]>a){
            a=di[i]; d=i;
        }
    }
    for(auto i:gr[v]) if(i!=par&&i!=c&&i!=d){
        down[i]=b+1; mdd[i]=a;
    }
    a=mdd[v]; b=down[v];
    for(auto i:gr[v]) if(i!=par&&i!=c){
        a=max(a,di[i],b+up[i]+1);
        b=max(b,up[i]+1);
    }
    down[c]=b+1; mdd[c]=a; a=mdd[v]; b=down[v];
    for(auto i:gr[v]) if(i!=par&&i!=d){
        a=max(a,di[i],b+up[i]+1);
        b=max(b,up[i]+1);
    }
    down[d]=b+1; mdd[d]=a;
    for(auto i:gr[v]) if(i!=par) dfs2(i,v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("d1p3.1-02.in", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m;
    fori(0,m){
        cin>>x>>y>>z; x++; y++;
        if(z==1){
            gr[x].pb(y); gr[y].pb(x);
        }
        else e.eb(x,y,z);
    }
    dfs(1); dfs2(1); seto(db,-inf); seto(si,-inf); seto(sd,-inf);
    fori(1,B) forj(0,n+1){
        x=p[i-1][j];
        p[i][j]=p[i-1][x]; pp[i][j]=pp[i-1][x];
        if(p[i][j]){
            if(i==1){
                c=0;
                fork(0,2) if(dc[x][k]&&dc[x][k]!=pp[i-1][j]) db[i][j]=max(db[i][j],di[dc[x][k]]);
                fork(0,3) if(uc[x][k]&&uc[x][k]!=pp[i-1][j]){
                    db[i][j]=max(db[i][j],c+up[uc[x][k]]+1,si[i-1][j]+up[uc[x][k]]+dep[x]+3,sd[i-1][x]+up[uc[x][k]]-dep[x]+3);
                    c=max(c,up[uc[x][k]]+1);
                }
                fork(0,2) if(uc[x][k]&&uc[x][k]!=pp[i-1][j]){
                    si[i][j]=max(si[i][j],up[uc[x][k]]+1-dep[x]);
                    sd[i][j]=max(sd[i][j],up[uc[x][k]]+1+dep[x]);
                }
            }
            else{
                y=pp[i-1][j];
                si[i][j]=max(si[i-1][j],si[i-1][x],si[1][y]); sd[i][j]=max(sd[i-1][j],sd[i-1][x],sd[1][y]);
                db[i][j]=max(db[i-1][j],db[i-1][x],si[i-1][j]+sd[i-1][x]+2,db[1][y],si[i-1][j]+sd[1][y]+2,si[1][y]+sd[i-1][x]+2);
            }
        }
    }
    ans=n*2-2-di[1];
    for(auto cur:e){
        tie(x,y,z)=cur; px=py=a=0;
        if(dep[x]>dep[y]) swap(x,y);
        bx=-dep[x]; by=-dep[y];
        fori(0,B) if((dep[y]-dep[x])&P2(i)){
            a=max(a,db[i][y],by+sd[i][y]+2,db[1][py],by+sd[1][py]+2,si[1][py]+sd[i][y]+2);
            by=max(by,si[i][y],si[1][py]);
            py=pp[i][y]; y=p[i][y];
        }
        ford(i,B-1,0) if(pp[i][x]!=pp[i][y]){
            a=max(a,db[i][x],bx+sd[i][x]+2,db[1][px],bx+sd[1][px]+2,si[1][px]+sd[i][x]+2);
            bx=max(bx,si[i][x],si[1][px]);
            px=pp[i][x]; x=p[i][x];
            a=max(a,db[i][y],by+sd[i][y]+2,db[1][py],by+sd[1][py]+2,si[1][py]+sd[i][y]+2);
            by=max(by,si[i][y],si[1][py]);
            py=pp[i][y]; y=p[i][y];
        }
        c=down[y]; a=max(a,max(bx,by)+c+2+dep[y]);
        forj(0,3) if(dc[y][j]&&dc[y][j]!=px&&dc[y][j]!=py) a=max(a,di[dc[y][j]]);
        forj(0,4) if(uc[y][j]&&uc[y][j]!=px&&uc[y][j]!=py){
            a=max(a,c+up[uc[y][j]]+1,max(bx,by)+up[uc[y][j]]+3+dep[y]);
            c=max(c,up[uc[y][j]]+1);
        }
        a=max(a,mdd[y],bx+by+2*dep[y]+2);
        c=x;
        tie(x,y,z)=cur;
        ans=min(ans,n*2-2+z-(dep[x]+dep[y]-2*dep[c])-a);
    }
    cout<<ans;
    return 0;
}
/**
need to subtract height dif

8 15
13 7
13 11
11 8
9 3
5 11
1 15
14 6
12 2
14 10
3 5
7 4
15 6
1 2
12 5 5
1 9 5
10 9 5
13 12 5
7 14 5
10 7 5
9 4 5
2 7 5
7 12 5
4 1 5
10 12 5
9 6 5
3 12 6
4 2 5
3 10 5
3 2 5
4 14 5
14 3 5
4 10 5
9 2 6
9 12 7
12 4 6
10 13 5
4 6 5
9 14 5
10 5 5

770.1

path can be above the lca

only one edge
(n-2)*2-path-epath+max(0,intersect-1)

binary lifting, do not consider bottom node
store longest disconnected, longest pair, longest single
disconnected: max
pair: max,connect singles
single:
*/
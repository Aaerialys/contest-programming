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
#define mt make_tuple
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
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
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

const int N=1010,NN=5000000,M=MOD;
struct Rect {
    int x1, y1, x2, y2;
    Rect(int a = 0, int b = 0, int c = 0, int d = 0): x1(a), y1(b), x2(c), y2(d) {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
    }
} rects[N];

vector<int> xs, ys;

int idx(int val, vector<int> vec) {
    return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

struct Node {
    int x, y;
    operator int() const { return x * ys.size() + y; }
    Node(int a = 0, int b = 0): x(a), y(b) {}
};

bool cmp_x(pair<Node, int> a, pair<Node, int> b) {
    if (a.first.y == b.first.y) return a.first.x < b.first.x;
    return a.first.y < b.first.y;
}
bool cmp_y(pair<Node, int> a, pair<Node, int> b) {
    if (a.first.x == b.first.x) return a.first.y < b.first.y;
    return a.first.x < b.first.x;
}

ll dist(Node a, Node b) { return abs(xs[a.x] - xs[b.x]) + abs(ys[a.y] - ys[b.y]); }

vector<Node> gr[NN];
bool vis[NN];
int T,x0,Y0,x1,Y1,n,a,b,c,d;

ll dijkstra(Node src, Node dest) {
    maxpq<pair<ll, Node>> pq;
    pq.push({0, src});
    while (pq.size()) {
        ll d = pq.top().first;
        Node curr = pq.top().second;
        pq.pop();
        if (curr == dest) return -d;
        if (!vis[curr]) {
            vis[curr] = true;
            for (Node i : gr[curr]) pq.push({d - dist(curr, i), i});
        }
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>T;
    while(T--){
        xs.clear(); ys.clear(); seto(vis,0);
        fori(0,NN) gr[i].clear();
        cin>>x0>>Y0>>x1>>Y1>>n; xs.pb(x0); xs.pb(x1); ys.pb(Y0); ys.pb(Y1);
        fori(0, n) {
            cin>>a>>b>>c>>d;
            rects[i]=Rect(a,b,c,d);
            xs.pb(a); xs.pb(c); ys.pb(b); ys.pb(d);
        }
        rects[n++]=Rect(x0,Y0,x0,Y0);
        rects[n++]=Rect(x1,Y1,x1,Y1);
        sort(all(xs)); xs.erase(unique(all(xs)), xs.end());
        sort(all(ys)); ys.erase(unique(all(ys)), ys.end());
        fori(0, n) {
            rects[i].x1=idx(rects[i].x1,xs);
            rects[i].x2=idx(rects[i].x2,xs);
            rects[i].y1=idx(rects[i].y1,ys);
            rects[i].y2=idx(rects[i].y2,ys);
        }
        x0=idx(x0,xs); Y0=idx(Y0,ys);
        x1=idx(x1,xs); Y1=idx(Y1,ys);
        fori(0, n) {
            foru(x, rects[i].x1, rects[i].x2) for (int y : {rects[i].y1, rects[i].y2}) {
                gr[Node(x, y)].pb(Node(x + 1, y));
                gr[Node(x + 1, y)].pb(Node(x, y));
            }
            foru(y, rects[i].y1, rects[i].y2) for (int x : {rects[i].x1, rects[i].x2}) {
                gr[Node(x, y)].pb(Node(x, y + 1));
                gr[Node(x, y + 1)].pb(Node(x, y));
            }
        }
        vector<pair<Node, int>> x_events;
        fori( 0, n) {
            foru(y, rects[i].y1, rects[i].y2 + 1) {
                x_events.pb({{rects[i].x1, y}, 1});
                x_events.pb({{rects[i].x2, y}, -1});
            }
        }
        sort(x_events.begin(), x_events.end(), cmp_x);
        int cnt = 0;
        fori(0, x_events.size()) {
            if (!cnt && i && x_events[i].first.y == x_events[i - 1].first.y) {
                gr[x_events[i].first].pb(x_events[i - 1].first);
                gr[x_events[i - 1].first].pb(x_events[i].first);
            }
            cnt += x_events[i].second;
        }

        vector<pair<Node, int>> y_events;
        fori(0, n) {
            foru(x, rects[i].x1, rects[i].x2 + 1) {
                y_events.pb({{x, rects[i].y1}, 1});
                y_events.pb({{x, rects[i].y2}, -1});
            }
        }
        sort(y_events.begin(), y_events.end(), cmp_y);
        cnt = 0;
        fori(0, y_events.size()) {
            if (!cnt && i && y_events[i].first.x == y_events[i - 1].first.x) {
                gr[y_events[i].first].pb(y_events[i - 1].first);
                gr[y_events[i - 1].first].pb(y_events[i].first);
            }
            cnt += y_events[i].second;
        }

        // Dijkstra
        ll ans = dijkstra({x0,Y0}, {x1, Y1});
        if (~ans) cout << ans << '\n';
        else cout << "No Path\n";
    }
    return 0;
}

/**

*/
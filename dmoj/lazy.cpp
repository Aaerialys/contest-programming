#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
#pragma GCC optimize("Ofast") 
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
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
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
typedef long long ll;

const int N=P2(17),M=1e9+7;
struct node{
    ll v,lz1,lz2;
};
class segTree{ //0 indexed
public:
    node seg[2*N];
    void pull(int num){
        seg[num].v=min(seg[num*2].v,seg[num*2+1].v);
    }
    void push(int num,int l,int r){
        if(seg[num].lz2){
            seg[num].v=seg[num].lz2;
            if(l!=r) fori(0,2){
                seg[2*num+i].lz2=seg[num].lz2;
                seg[2*num+i].lz1=0;
            }
            seg[num].lz2=0;
        }
        if(seg[num].lz1){
            seg[num].v+=seg[num].lz1;
            if(l!=r) fori(0,2){
                if(seg[2*num+i].lz2) seg[2*num+i].lz2+=seg[num].lz1;
                else seg[2*num+i].lz1+=seg[num].lz1;
            }
            seg[num].lz1=0;
        }
    }
    void build(int *arr){
        fori(0,N) seg[i+N].v=arr[i];
        ford(i,N-1,1) pull(i);
    }
    void upd(int lo,int hi,int val,bool t,int num=1,int l=0,int r=N-1){
        push(num,l,r);
        if(hi<l||r<lo) return;
        if(lo<=l&&r<=hi){
            if(t) seg[num].lz2=val;
            else seg[num].lz1=val;
            push(num,l,r);
            return;
        }
        int mid=(l+r)/2;
        upd(lo,hi,val,t,num*2,l,mid); upd(lo,hi,val,t,num*2+1,mid+1,r);
        pull(num);
    }
    ll query(int lo,int hi,int num=1,int l=0,int r=N-1){
        push(num,l,r);
        if(hi<l||r<lo) return INF;
        if(lo<=l&&r<=hi) return seg[num].v;
        int mid=(l+r)/2;
        return min(query(lo,hi,num*2,l,mid),query(lo,hi,2*num+1,mid+1,r));
    }
};
segTree st;
int n,q,t,a,b,c,arr[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(0,n) cin>>arr[i];
    st.build(arr);
    fori(0,q){
        cin>>t>>a>>b;
        if(t==1||t==2){
            cin>>c;
            st.upd(a-1,b-1,c,t-1);
        }
        else cout<<st.query(a-1,b-1)<<"\n";
    }
    return 0;
}
/**

*/
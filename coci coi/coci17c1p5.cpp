#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1<<18;
struct node
{
    int l,r,v;
};

class segTree
{
public:
    node seg[2*N]; //4*NN if NN is not a power of 2
    segTree()
    {
        build();
    }
    void build()
    {
        build(1,N,1);
    }
    void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r;
        if(l==r)
        {
            seg[num].v=inf;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
        seg[num].v=min(seg[2*num].v,seg[2*num+1].v);
    }
    void update(int pos,int v)
    {
        update(pos,v,1);
    }
    void update(int pos,int v,int num)
    {
        if(seg[num].l==pos&&seg[num].r==pos)
        {
            seg[num].v=v;
            return;
        }
        int mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid)
            update(pos,v,2*num);
        else
            update(pos,v,2*num+1);
        seg[num].v=min(seg[2*num].v,seg[2*num+1].v);
    }
    int rmq(int l,int r)
    {
        return rmq(l,r,1);
    }
    int rmq(int l,int r,int num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return rmq(l,r,2*num);
        if(l>mid)
            return rmq(l,r,2*num+1);
        return min(rmq(l,mid,2*num),rmq(mid+1,r,2*num+1));
    }
    int query(int l,int v)
    {
        return query(l,N,v,1);
    }
    int query(int l,int r,int v,int num)
    {
        if(l==r)
            return (seg[num].v<=v? l: -1);
        int mid=(seg[num].l+seg[num].r)/2;
        if(l>mid)
            return query(l,r,v,2*num+1);
        if(rmq(l,mid)<=v)
            return query(l,mid,v,2*num);
        if(rmq(mid+1,r)<=v)
            return query(mid+1,r,v,2*num+1);
        return -1;
    }
};

segTree st;
int n,q,a,b,c;
char ch;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>q;
    fori(0,q)
    {
        cin>>ch>>a>>b;
        if(ch=='M')
            st.update(b,a);
        if(ch=='D')
            cout<<st.query(b,a)<<"\n";
    }
    return 0;
}
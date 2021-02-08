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
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
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
        seg[num].v=max(seg[2*num].v,seg[2*num+1].v);
    }
    int query(int l,int r)
    {
        return query(l,r,1);
    }
    int query(int l,int r,int num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        if(l>mid)
            return query(l,r,2*num+1);
        return max(query(l,mid,2*num),query(mid+1,r,2*num+1));
    }
};
segTree lm,rm,mlen;
int n,q,arr[N],x,y,ans[N];
unordered_map<int,int> diverse;
pair<pii,int> que[N];
bool cmp(pair<pii,int> xx,pair<pii,int> yy)
{
    return xx.pf.ps<yy.pf.ps;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>q;
    fori(1,n+1)
        cin>>arr[i];
    fori(0,q)
    {
        cin>>que[i].pf.pf>>que[i].pf.ps;
        que[i].ps=i;
    }
    sort(que,que+q,cmp);
    que[q]={{0,inf},q}; x=1;
    fori(1,n+1)
    {
        diverse[arr[i]]++;
        while(diverse.size()<i-x+1)
        {
            diverse[arr[x]]--;
            if(diverse[arr[x]]==0)
                diverse.erase(arr[x]);
            x++;
        }
        rm.update(x,i);
        lm.update(i,-x);
        mlen.update(x,i-x+1);
        for(;que[y].pf.ps==i;y++)
            ans[que[y].ps]=mlen.query(que[y].pf.pf,que[y].pf.ps);
    }
    fori(0,q)
    {
        ans[que[i].ps]=max(ans[que[i].ps],rm.query(1,que[i].pf.pf)-que[i].pf.pf+1);
        ans[que[i].ps]=max(ans[que[i].ps],que[i].pf.ps+lm.query(que[i].pf.ps,n)+1);
        ans[que[i].ps]=min(ans[que[i].ps],que[i].pf.ps-que[i].pf.pf+1);
    }
    fori(0,q)
        cout<<ans[i]<<"\n";
    return 0;
}
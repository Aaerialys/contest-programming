#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1<<20;
int val[N],n,K,q,x,v,a,b,c,lm,rm,l0,r0,ans;
deque<int> dq;

struct node
{
    int l,r;
    int v,rv;
};
node seg[N*2];

    inline void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r;
        if(l==r)
        {
            if(l<=n)
                seg[num].v=l;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,(num<<1)); build(mid+1,r,(num<<1)|1);
        if(val[seg[(num<<1)].v]>val[seg[(num<<1)|1].v])
            seg[num].v=seg[(num<<1)].v;
        else
            seg[num].v=seg[(num<<1)|1].v;
        seg[num].rv=max(seg[(num<<1)].rv,seg[(num<<1)|1].rv);

    }
    inline void update(int pos,int num)
    {
        for(num=(pos+N-1)>>1;num;num>>=1)
            seg[num].v=(val[seg[(num<<1)].v]>val[seg[(num<<1)|1].v])? seg[num].v=seg[(num<<1)].v: seg[num].v=seg[(num<<1)|1].v;
    }
    inline void updateR(int pos,int v,int num)
    {
        num=pos+N-1;
        seg[num].rv=v;
        for(num>>=1;num;num>>=1)
            seg[num].rv=max(seg[(num<<1)].rv,seg[(num<<1)|1].rv);
    }
    inline int query(int l,int r)
    {
        if(r==0||l>n)
            return 0;
        int cur=0;
        for(l+=N-1,r+=N-1;l<=r;l>>=1,r>>=1)
        {
            if(l&1)
                cur=(val[cur]==val[seg[l++].v]&&cur>seg[l-1].v||val[cur]>val[seg[l-1].v])? cur: seg[l-1].v;
            if(!(r&1))
                cur=(val[cur]==val[seg[r--].v]&&cur>seg[r+1].v||val[cur]>val[seg[r+1].v])? cur: seg[r+1].v;
        }
        //if(cur!=d)
          //  cout<<l<<" "<<r<<" "<<cur<<" "<<d<<endl;
        return cur;
    }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("boring.14.in", "r", stdin);
    cin>>n>>K>>q; val[0]=-1;
    fori(1,n+1)
        cin>>val[i];
    build(1,N,1);
    fori(1,n+1)
    {
        lm=query(max(1,i-K+1),i-1); rm=query(i+1,min(n,i+K-1));
        if(val[i]>=val[lm]&&val[i]>val[rm])
            updateR(i,val[i]+max(val[lm],val[rm]),1);
    }
    ans=seg[1].rv;
    cout<<ans<<"\n";
    fori(0,q)
    {
        cin>>x>>v; //x^=ans; v^=ans;
        val[x]=v;
        update(x,1);
        lm=query(max(1,x-K+1),x-1); rm=query(x+1,min(n,x+K-1));
        if(v>=val[lm]&&v>val[rm])
            updateR(x,v+max(val[lm],val[rm]),1);
        else
        {
            updateR(x,0,1);
            if(lm!=0)
            {
                l0=query(max(1,lm-K+1),lm-1); r0=query(lm+1,min(n,lm+K-1));
                if(val[lm]>=val[l0]&&val[lm]>val[r0])
                    updateR(lm,val[lm]+max(val[l0],val[r0]),1);
            }
            if(rm!=0)
            {
                l0=query(max(1,rm-K+1),rm-1); r0=query(rm+1,min(n,rm+K-1));
                if(val[rm]>=val[l0]&&val[rm]>val[r0])
                    updateR(rm,val[rm]+max(val[l0],val[r0]),1);
            }
        }
        ans=seg[1].rv;
        cout<<ans<<"\n";
    }
    return 0;
}

/*
array
segtree: max element (store location)
max array: maximum in range k, left of element i, including elment i
max array segtree: maximum of range maximums

*/
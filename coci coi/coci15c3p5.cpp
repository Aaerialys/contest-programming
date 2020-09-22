#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

const int N=1<<17;

int n,q,K,a,b,c,arr[N];
bool inc[51];

struct node
{
    int l,r,v;
    pii lm[51],rm[51];
};

node seg[2*N];
class segTree
{
public:
    inline void build()
    {
        build(1,N,1);
    }
    inline void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r; seg[num].v=inf;
        if(l==r)
        {
            fori(0,K)
                seg[num].lm[i]={inf,i};
            fori(0,K)
                seg[num].rm[i]={-inf,i};
            if(l>n)
                return;
            seg[num].lm[arr[l-1]]=seg[num].rm[arr[l-1]]={l,arr[l-1]};
            swap(seg[num].lm[arr[l-1]],seg[num].lm[0]); swap(seg[num].rm[arr[l-1]],seg[num].rm[K-1]);
            if(K==1)
                seg[num].v=1;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,(num<<1)); build(mid+1,r,(num<<1)+1);
        seg[num].v=min(seg[(num<<1)].v,seg[(num<<1)+1].v);
        int le=0; seto(inc,0);
        fori(0,K)
        {
            for(;le<K&&!inc[seg[(num<<1)].rm[i].ps];le++)
                inc[seg[(num<<1)+1].lm[le].ps]=true;
            seg[num].v=min(seg[num].v,seg[(num<<1)+1].lm[le-1].pf-seg[(num<<1)].rm[i+1].pf+1);
        }
        le=0; seto(inc,0);
        fori(0,K)
        {
            if(seg[num*2].lm[i].pf==inf)
                break;
            seg[num].lm[le++]=seg[num*2].lm[i];
            inc[seg[num*2].lm[i].ps]=true;
        }
        fori(0,K)
            if(!inc[seg[num*2+1].lm[i].ps])
            {
                seg[num].lm[le++]=seg[num*2+1].lm[i];
                inc[seg[num*2+1].lm[i].ps]=true;
            }
        le--; seto(inc,0);
        ford(i,K-1,0)
        {
            if(seg[num*2+1].rm[i].pf==-inf)
                break;
            seg[num].rm[le--]=seg[num*2+1].rm[i];
            inc[seg[num*2+1].rm[i].ps]=true;
        }
        ford(i,K-1,0)
            if(!inc[seg[num*2].rm[i].ps])
                seg[num].rm[le--]=seg[num*2].rm[i];
    }
    inline void update(int pos,int v)
    {
        update(pos,v,1);
    }
    inline void update(int pos,int v,int num)
    {
        num=pos+N-1;
        fori(0,K)
        {
            seg[num].lm[i]={inf,i};
            seg[num].rm[i]={-inf,i};
        }
        seg[num].lm[v]=seg[num].rm[v]={pos,v};
        swap(seg[num].lm[v],seg[num].lm[0]); swap(seg[num].rm[v],seg[num].rm[K-1]);
        for(num=(pos+N-1)>>1;num;num>>=1)
        {
            seg[num].v=min(seg[(num<<1)].v,seg[(num<<1)+1].v);
            int le=0; seto(inc,0);
            fori(0,K)
            {
                for(;le<K&&!inc[seg[(num<<1)].rm[i].ps];le++)
                    inc[seg[(num<<1)+1].lm[le].ps]=true;
                seg[num].v=min(seg[num].v,seg[(num<<1)+1].lm[le-1].pf-seg[(num<<1)].rm[i+1].pf+1);
            }
            le=0; seto(inc,0);
            fori(0,K)
            {
                if(seg[num*2].lm[i].pf==inf)
                    break;
                seg[num].lm[le++]=seg[num*2].lm[i];
                inc[seg[num*2].lm[i].ps]=true;
            }
            fori(0,K)
                if(!inc[seg[num*2+1].lm[i].ps])
                {
                    seg[num].lm[le++]=seg[num*2+1].lm[i];
                    inc[seg[num*2+1].lm[i].ps]=true;
                }
            le--; seto(inc,0);
            ford(i,K-1,0)
            {
                if(seg[num*2+1].rm[i].pf==-inf)
                    break;
                seg[num].rm[le--]=seg[num*2+1].rm[i];
                inc[seg[num*2+1].rm[i].ps]=true;
            }
            ford(i,K-1,0)
                if(!inc[seg[num*2].rm[i].ps])
                    seg[num].rm[le--]=seg[num*2].rm[i];
        }
    }
    inline int query(int l,int r)
    {
        return seg[1].v;
    }
};

segTree st;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("nisu_kameleoni.in.1a", "r", stdin);
    cin>>n>>K>>q;
    fori(0,n)
    {
        cin>>arr[i];
        arr[i]--;
    }
    st.build();
    fori(0,q)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            st.update(b,c-1);
            arr[b-1]=c-1;
        }
        if(a==2)
        {
            b=st.query(1,n);
            if(b>N)
                cout<<"-1\n";
            else
                cout<<b<<"\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
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

const int N=500010;
int sz;

struct node
{
    int lc,rc,v;
};

node seg[22000000];

class segTree
{
public:
    int root;
    segTree()
    {
        build();
    }
    void build()
    {
        root=++sz;
        seg[sz]={0,0,0};
    }
    void update(int pos)
    {
        update(pos,root,1,N);
    }
    void update(int pos,int num,int l,int r)
    {
        seg[num].v++;
        if(l==pos&&r==pos)
            return;
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            if(seg[num].lc==0)
            {
                seg[num].lc=++sz;
                seg[sz]={0,0,0};
            }
            update(pos,seg[num].lc,l,mid);
        }
        if(pos>mid)
        {
            if(seg[num].rc==0)
            {
                seg[num].rc=++sz;
                seg[sz]={0,0,0};
            }
            update(pos,seg[num].rc,mid+1,r);
        }
    }
    int query(int pos)
    {
        return query(pos,root,1,N);
    }
    int query(int pos,int num,int l,int r)
    {
        if(r<=pos)
            return seg[num].v;
        int mid=(l+r)/2;
        if(pos<=mid)
            return (seg[num].lc? query(pos,seg[num].lc,l,mid):0);
        return (seg[num].lc? query(pos,seg[num].lc,l,mid):0)+(seg[num].rc? query(pos,seg[num].rc,mid+1,r):0);
    }
};
segTree tree[N];

class biTree
{
    public:
    void add(int x,int y)
    {
        while(x<N)
        {
            tree[x].update(y);
            x+=(x&(-x));
        }
    }
    int addto(int x,int y)
    {
        int sum=0;
        while(x>0)
        {
            sum+=tree[x].query(y);
            x-=(x&(-x));
        }
        return sum;
    }
    int memcheck()
    {
        return sz;
    }
};
biTree bit;

pair<int,pii> stu[N];
int n,t,x,y,z;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(1,n+1)
    {
        cin>>x;
        stu[x].pf=i;
    }
    fori(1,n+1)
    {
        cin>>x;
        stu[x].ps.pf=i;
    }
    fori(1,n+1)
    {
        cin>>x;
        stu[x].ps.ps=i;
    }
    sort(stu,stu+n+1);
    fori(1,n+1)
    {
        if(bit.addto(stu[i].ps.pf,stu[i].ps.ps)==0)
            t++;
        bit.add(stu[i].ps.pf,stu[i].ps.ps);
    }
    cout<<t;
    return 0;
}
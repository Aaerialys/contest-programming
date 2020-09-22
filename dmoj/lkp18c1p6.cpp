#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

const long long N=1<<18;

struct node
{
    long long l,r,v;
};
class segTree
{
public:
    node seg[2*N];
    segTree()
    {
        build();
    }
    void build()
    {
        build(1,N,1);
    }
    void build(long long l,long long r,long long num)
    {
        seg[num].l=l; seg[num].r=r;
        if(l==r)
        {
            seg[num].v=LLONG_MIN/4;
            return;
        }
        long long mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
        seg[num].v=max(seg[2*num].v,seg[2*num+1].v);
    }
    void update(long long pos,long long v)
    {
        update(pos,v,1);
    }
    void update(long long pos,long long v,long long num)
    {
        if(seg[num].l==pos&&seg[num].r==pos)
        {
            seg[num].v=max(seg[num].v,v);
            return;
        }
        long long mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid)
            update(pos,v,2*num);
        else
            update(pos,v,2*num+1);
        seg[num].v=max(seg[2*num].v,seg[2*num+1].v);
    }
    long long query(long long l,long long r)
    {
        return query(l,r,1);
    }
    long long query(long long l,long long r,long long num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        long long mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        if(l>mid)
            return query(l,r,2*num+1);
        return max(query(l,mid,2*num),query(mid+1,r,2*num+1));
    }
};

struct point
{
    long long x,y,i,t;
};
bool cmp(point a,point b)
{
    if(a.x==b.x)
        return a.t<b.t;
    return a.x<b.x;
}

long long n,m,x,y,a,b,t,ans[N];
vector<point> p;
vector<long long> ycmp;
unordered_map<long long,long long> cord;
segTree s1,s2,s3,s4;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x>>y;
        p.push_back({x,y,i,2});
        ycmp.push_back(y);
    }
    cin>>m;
    fori(0,m)
    {
        cin>>x>>y;
        p.push_back({x,y,i,1});
        ycmp.push_back(y);
    }
    sort(ycmp.begin(),ycmp.end());
    fori(0,ycmp.size())
        cord[ycmp[i]]=i+1;
    sort(p.begin(),p.end(),cmp);
    for(auto i:p)
    {
        if(i.t==1)
        {
            s1.update(cord[i.y],i.x-i.y);
            s2.update(cord[i.y],i.x+i.y);
        }
        if(i.t==2)
            ans[i.i]=min(i.x-i.y-s1.query(cord[i.y],N),i.x+i.y-s2.query(1,cord[i.y]));
    }
    reverse(p.begin(),p.end());
    for(auto i:p)
    {
        i.x=-i.x;
        if(i.t==1)
        {
            s3.update(cord[i.y],i.x-i.y);
            s4.update(cord[i.y],i.x+i.y);
        }
        if(i.t==2)
        {
            ans[i.i]=min(ans[i.i],min(i.x-i.y-s3.query(cord[i.y],N),i.x+i.y-s4.query(1,cord[i.y])));
        }
    }
    fori(0,n)
        t+=ans[i];
    cout<<t<<endl;
    return 0;
}
/**
2 segment tree - 1 store min(x+y), one store max(y-x), position based on y
line sweep insert long longo 2 seg tree
query - 1st tree from point upwards, 2nd tree from point down
*/
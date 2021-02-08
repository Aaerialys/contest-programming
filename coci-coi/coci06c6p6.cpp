#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

class biTree
{
    public:
    int N,M;
    int tree[1050][1050];
    biTree()
    {
        N=M=1050;
    }
    void add(int x,int y,int v)
    {
        int y0;
        y0=y;
        while(x<=N)
        {
            y=y0;
            while(y<=M)
            {
                tree[x][y]+=v;
                y+=(y&(-y));
            }
            x+=(x&(-x));
        }
    }
    long long addto(int x,int y)
    {
        long long sum=0,y0;
        y0=y;
        while(x>0)
        {
            y=y0;
            while(y>0)
            {
                sum+=tree[x][y];
                y-=(y&(-y));
            }
            x-=(x&(-x));
        }
        return sum;
    }
};

class rct
{
public:
    int t,l,a1,b1,a2,b2;
};

bool cmp(rct a,rct b)
{
    if(a.l==b.l)
        return a.t<b.t;
    return a.l<b.l;
}

biTree l,r;
vector<rct> xy,yz,zx;
int n,x_1,x2,y_1,y2,z_1,z2;
long long t;
rct a;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x_1>>y_1>>z_1>>x2>>y2>>z2;
        if(x_1>x2)
            swap(x_1,x2);
        if(y_1>y2)
            swap(y_1,y2);
        if(z_1>z2)
            swap(z_1,z2);
        if(x_1==x2)
        {
            xy.push_back({0,y_1,x_1,z_1,x2,z2});
            zx.push_back({1,x_1,z_1,y_1,z2,y2});
            xy.push_back({2,y2,x_1,z_1,x2,z2});
        }
        if(y_1==y2)
        {
            yz.push_back({0,z_1,y_1,x_1,y2,x2});
            xy.push_back({1,y_1,x_1,z_1,x2,z2});
            yz.push_back({2,z2,y_1,x_1,y2,x2});
        }
        if(z_1==z2)
        {
            zx.push_back({0,x_1,z_1,y_1,z2,y2});
            yz.push_back({1,z_1,y_1,x_1,y2,x2});
            zx.push_back({2,x2,z_1,y_1,z2,y2});
        }
    }
    sort(xy.begin(),xy.end(),cmp);
    sort(yz.begin(),yz.end(),cmp);
    sort(zx.begin(),zx.end(),cmp);
    fori(0,xy.size())
    {
        a=xy[i];
        if(xy[i].t<=1)
        {
            t+=l.addto(xy[i].a2,xy[i].b2)-l.addto(xy[i].a1-1,xy[i].b2);
            t-=r.addto(xy[i].a2,xy[i].b1-1)-r.addto(xy[i].a1-1,xy[i].b1-1);
        }
        if(xy[i].t==0)
        {
            l.add(xy[i].a1,xy[i].b1,1);
            r.add(xy[i].a2,xy[i].b2,1);
        }
        if(xy[i].t==2)
        {
            l.add(xy[i].a1,xy[i].b1,-1);
            r.add(xy[i].a2,xy[i].b2,-1);
        }
    }
    fori(0,yz.size())
    {
        a=yz[i];
        if(yz[i].t<=1)
        {
            t+=l.addto(yz[i].a2,yz[i].b2)-l.addto(yz[i].a1-1,yz[i].b2);
            t-=r.addto(yz[i].a2,yz[i].b1-1)-r.addto(yz[i].a1-1,yz[i].b1-1);
        }
        if(yz[i].t==0)
        {
            l.add(yz[i].a1,yz[i].b1,1);
            r.add(yz[i].a2,yz[i].b2,1);
        }
        if(yz[i].t==2)
        {
            l.add(yz[i].a1,yz[i].b1,-1);
            r.add(yz[i].a2,yz[i].b2,-1);
        }
    }
    fori(0,zx.size())
    {
        a=zx[i];
        if(zx[i].t<=1)
        {
            t+=l.addto(zx[i].a2,zx[i].b2)-l.addto(zx[i].a1-1,zx[i].b2);
            t-=r.addto(zx[i].a2,zx[i].b1-1)-r.addto(zx[i].a1-1,zx[i].b1-1);
        }
        if(zx[i].t==0)
        {
            l.add(zx[i].a1,zx[i].b1,1);
            r.add(zx[i].a2,zx[i].b2,1);
        }
        if(zx[i].t==2)
        {
            l.add(zx[i].a1,zx[i].b1,-1);
            r.add(zx[i].a2,zx[i].b2,-1);
        }
    }
    cout<<t;
    return 0;
}
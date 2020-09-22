#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

class pi
{
public:
    int a,b,d;
};
bool cmp(pi a,pi b)
{
    return a.d<b.d;
}

int n,best[2010],ne[2010],xx[2010],yy[2010],a,b,c;
vector<pi> p;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    xx[n]=yy[n]=0;
    fori(0,n)
    {
        cin>>xx[i]>>yy[i];
        forj(0,i)
            p.push_back({i,j,pow(xx[i]-xx[j],2)+pow(yy[i]-yy[j],2)});
    }
    forj(0,n)
        p.push_back({n,j,pow(xx[n]-xx[j],2)+pow(yy[n]-yy[j],2)});
    sort(p.begin(),p.end(),cmp);
    fori(0,p.size())
    {
        set<int> upd;
        ne[p[i].a]=best[p[i].a]; ne[p[i].b]=best[p[i].b];
        upd.insert(p[i].a); upd.insert(p[i].b);
        ne[p[i].a]=max(ne[p[i].a],best[p[i].b]+1);
        if(p[i].a!=n)
            ne[p[i].b]=max(ne[p[i].b],best[p[i].a]+1);
        i++;
        while(i<p.size()&&p[i].d==p[i-1].d)
        {
            ne[p[i].a]=max(ne[p[i].a],best[p[i].a]); ne[p[i].b]=max(ne[p[i].b],best[p[i].b]);
            upd.insert(p[i].a); upd.insert(p[i].b);
            ne[p[i].a]=max(ne[p[i].a],best[p[i].b]+1);
            if(p[i].a!=n)
                ne[p[i].b]=max(ne[p[i].b],best[p[i].a]+1);
            i++;
        }
        i--;
        for(auto i:upd)
        {
            best[i]=ne[i];
            ne[i]=0;
        }
    }
    cout<<best[n];
    return 0;
}
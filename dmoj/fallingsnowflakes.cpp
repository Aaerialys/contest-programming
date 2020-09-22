#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=5010;
int tree[N][N];

class biTree
{
    public:
    void add(int x,int y,int v)
    {
        int y0;
        x++;
        y++;
        y0=y;
        while(x<=N)
        {
            y=y0;
            while(y<=N)
            {
                tree[x][y]+=v;
                y+=(y&(-y));
            }
            x+=(x&(-x));
        }
    }
    int addto(int x,int y)
    {
        x++;
        y++;
        int sum=0,y0;
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
struct str
{
    int t,e,a,b,c,d,i;
};
bool cmp(str x,str y)
{
    if(x.t==y.t)
        return x.e<y.e;
    return x.t<y.t;
}
int n,m,q,a,b,c,d,e,ans[100010];
char ch;
biTree bit;
vector<str> vt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>q;
    fori(i,0,m)
    {
        cin>>a>>b>>c>>d; a++; b++;
        vt.push_back({c,0,a,b,0,0,0});
        vt.push_back({d,1,a,b,0,0,0});
    }
    fori(i,0,q)
    {
        cin>>ch;
        if(ch=='R')
        {
            cin>>a>>b>>c; a++; b++;
            vt.push_back({c,2,a,b,0,0,i});
        }
        if(ch=='C')
        {
            cin>>a>>b>>c; a++; b++;
            vt.push_back({c,3,a,b,0,0,i});
        }
        if(ch=='V')
        {
            cin>>a>>b>>c>>d>>e; a++; b++; c++; d++;
            vt.push_back({e,4,a,b,c,d,i});
        }
    }
    sort(vt.begin(),vt.end(),cmp);
    for(auto i:vt)
    {
        if(i.e==0)
            bit.add(i.a,i.b,1);
        if(i.e==1)
            bit.add(i.a,i.b,-1);
        if(i.e==2)
            ans[i.i]=bit.addto(i.b,n)-bit.addto(i.a-1,n);
        if(i.e==3)
            ans[i.i]=bit.addto(n,i.b)-bit.addto(n,i.a-1);
        if(i.e==4)
        {
            ans[i.i]=bit.addto(i.b,n)-bit.addto(i.a-1,n)+bit.addto(n,i.d)-bit.addto(n,i.c-1)-(bit.addto(i.b,i.d)-bit.addto(i.b,i.c-1)-bit.addto(i.a-1,i.d)+bit.addto(i.a-1,i.c-1));
        }
    }
    fori(i,0,q)
        cout<<ans[i]<<"\n";
    return 0;
}
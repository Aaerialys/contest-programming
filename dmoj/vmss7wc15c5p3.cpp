#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

class biTree
{
    public:
    long long N;
    vector<long long> tree;
    biTree(long long n)
    {
        N=n;
        fori(0,n+1)
        {
            tree.push_back(0);
        }
    }
    void add(long long x,long long v)
    {
        x++;
        while(x<=N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    long long addto(long long x)
    {
        x++;
        long long sum=0;
        while(x>0)
        {
            sum+=tree[x];
            x-=(x&(-x));
        }
        return sum;
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,a,b,c,d,x=0;
    cin>>n;
    biTree t[2010](2010);
    fori(0,n)
    {
        cin>>a>>b>>c>>d;
        if(a==1)
        {
            t[b+c].add(c,d);
        }
        if(a==2)
        {
            x+=t[b+c].addto(c+d)-t[b+c].addto(c-1);
        }
    }
    cout<<x%(1000000007)<<endl;
    return 0;
}
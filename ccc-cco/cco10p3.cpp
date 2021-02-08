#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;
const long long L=(1<<20)+1;
long long tree[L];
long long numb[L];
long long f[L],id[L];
unordered_map<long long,long long> id2;
unordered_map<long long,long long> f2;
class biTree
{
    public:
    long long N;
    biTree(long long n)
    {
        N=n;
    }
    long long get(long long x)
    {
        return numb[x+1];
    }
    void add(long long x,long long v)
    {
        x++;
        numb[x]+=v;
        while(x<=N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    long long addto(long long x)
    {
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
    long long n;
    cin>>n;
    vector<long long> xx;
    char ch[n];
    long long a[n],b[n];
    fori(0,n)
    {
        cin>>ch[i]>>a[i];
        if(ch[i]=='N'||ch[i]=='M')
        {
            cin>>b[i];
            xx.push_back(b[i]);
        }
    }
    sort(xx.begin(),xx.end());
    reverse(xx.begin(),xx.end());
    fori(0,xx.size())
    {
        id[i]=xx[i];
        id2.emplace(xx[i],i);
    }
    biTree t(L);
    fori(0,n)
    {
        if(ch[i]=='N')
        {
            f[a[i]]=b[i];
            f2.emplace(b[i],a[i]);
            t.add(id2[b[i]],1);
        }
        if(ch[i]=='M')
        {
            t.add(id2[f[a[i]]],-1);
            f[a[i]]=b[i];
            f2.emplace(b[i],a[i]);
            t.add(id2[b[i]],1);
        }
        if(ch[i]=='Q')
        {
            long long x=0,y=L>>1;
            forj(0,20)
            {
                if(tree[x+y]<a[i])
                {
                    a[i]-=tree[x+y];
                    x+=y;
                }
                y=(y>>1);
            }
            cout<<f2[id[x]]<<"\n";
        }
    }
    return 0;
}
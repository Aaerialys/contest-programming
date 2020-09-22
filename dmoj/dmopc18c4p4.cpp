#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

long long tree[200010];

class biTree
{
    public:
    long long N;
    biTree(long long n)
    {
        N=n;
    }
    void add(long long x,long long v)
    {
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

const long long N=200010;
biTree bt(N);
long long n,q,x=1,y,ans[N],sum[N];
pair<long long,long long> numb[N],qk[N],qr[N];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    fori(1,n+1)
    {
        cin>>numb[i].first;
        numb[i].second=i;
        sum[i]=sum[i-1]+numb[i].first;
    }
    fori(0,q)
    {
        cin>>qr[i].first>>qr[i].second>>qk[i].first;
        qk[i].second=i;
    }
    sort(numb+1,numb+n+1); sort(qk,qk+q);
    fori(0,q)
    {
        while(x<=n&&numb[x].first<qk[i].first)
        {
            bt.add(numb[x].second,numb[x].first);
            x++;
        }
        y=qk[i].second;
        ans[y]=sum[qr[y].second]-sum[qr[y].first-1];
        ans[y]-=2*bt.addto(qr[y].second)-2*bt.addto(qr[y].first-1);
    }
    fori(0,q)
        cout<<ans[i]<<"\n";
    return 0;
}
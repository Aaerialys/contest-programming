#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;
int tree[1000010];
class biTree
{
    public:
    long long N;
    biTree(int n)
    {
        N=n;
    }
    void add(int x,int v)
    {
        x++;
        while(x<=N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    int addto(int x)
    {
        x++;
        int sum=0;
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
    long long n,p;
    long long t=0;
    cin>>n;
    n++;
    long long pr[n];
    pair<long long,int> pr1[n];
    fori(1,n)
    {
        cin>>pr[i];
    }
    cin>>p;
    pr[0]=0;
    pr1[0]=make_pair(0,0);
    fori(1,n)
    {
        pr[i]-=p;
        pr[i]+=pr[i-1];
        pr1[i]=make_pair(pr[i],i);
    }
    sort(pr1,pr1+n);
    fori(0,n)
    {
        pr[pr1[i].second]=i;
    }
    biTree tr(n);
    tr.add(pr[0],1);
    fori(1,n)
    {
        t+=tr.addto(pr[i]);
        tr.add(pr[i],1);
    }
    cout<<t;/**/
    return 0;
}
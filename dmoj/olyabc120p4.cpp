#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

long long parent[100100];
long long sz[100100];
class djSet
{
public:
    djSet()
    {
        fori(0,100100)
            parent[i]=i;
        fori(0,100100)
            sz[i]=1;
    }
    long long lead(long long x)
    {
        if(parent[x]!=x)
            parent[x]=lead(parent[x]);
        return parent[x];
    }
    void link(long long x,long long y)
    {
        x=lead(x);
        y=lead(y);
        if(x!=y)
            sz[y]+=sz[x];
        parent[x]=y;
    }
};

djSet gr;
long long n,m,a,b,aa[100100],bb[100100],x,cn,ans[100100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    ford(i,m,1)
        cin>>aa[i]>>bb[i];
    cn=ans[0]=n*(n-1)/2;
    fori(1,m+1)
    {
        a=aa[i]-1; b=bb[i]-1;
        if(gr.lead(a)!=gr.lead(b))
            cn-=sz[gr.lead(a)]*sz[gr.lead(b)];
        ans[i]=cn;
        gr.link(a,b);
    }
    ford(i,m-1,0)
        cout<<ans[i]<<"\n";
    return 0;
}
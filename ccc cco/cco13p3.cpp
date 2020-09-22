#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

const long long N=400100;
long long n,a,b,prn[N],prd[N],inn[N],ind[N],sn,sd;
vector<long long> gr[N];

void dfs(long long p,long long v)
{
    for(auto i:gr[v])
        if(i!=p)
            dfs(v,i);
    prn[v]=sn=1; prd[v]=sd=-1;
    for(auto i:gr[v])
    {
        if(i==p) continue;
        if(prd[i]==prd[v])
            prn[v]+=prn[i];
        if(prd[i]>prd[v])
        {
            prd[v]=prd[i];
            prn[v]=prn[i];
        }//*/
    }
    for(auto i:gr[v])
    {
        if(i==p) continue;
        if(prd[i]==sd)
            sn+=prn[i];
        if(prd[i]>sd&&prd[i]!=prd[v])
        {
            sd=prd[i];
            sn=prn[i];
        }
    }
    a=0;
    for(auto i:gr[v])
    {
        if(i==p) continue;
        if(prd[i]==prd[v])
        {
            inn[v]+=a*prn[i];
            a+=prn[i];
        }
    }
    prd[v]++;
    sd++;
    if(inn[v]>0)
    {
        ind[v]=prd[v]*2;
    }
    else
    {
        ind[v]=prd[v]+sd;
        inn[v]=sn*prn[v];
    }
    for(auto i:gr[v])
    {
        if(i==p) continue;
        if(ind[i]==ind[v])
            inn[v]+=inn[i];
        if(ind[i]>ind[v])
        {
            ind[v]=ind[i];
            inn[v]=inn[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(1,n)
    {
        cin>>a>>b;
        gr[a].push_back(b); gr[b].push_back(a);
    }
    dfs(0,1);
    cout<<ind[1]+1<<" "<<inn[1]<<endl;
    return 0;
}
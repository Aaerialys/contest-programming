#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

const long long N=1000100;
long long n,arr[N],a,b,c,best[N][4],xx,t,ps[N];
bool vis[N];
vector<long long> gt[N],gf[N];
void fv(long long v,long long p){
    if(xx!=-1)
        return;
    vis[v]=true;
    for(auto i:gt[v]){
        if(vis[i])
            xx=v;
        else
            fv(i,v);
    }
    vis[v]=false;
}

void sm(long long v,long long p){
    vis[v]=true;
    best[v][1]=best[v][3]=arr[v];
    for(auto i:gf[v]){
        if(!vis[i])
        {
            sm(i,v);
            best[v][0]+=max(best[i][0],best[i][1]);
            best[v][1]+=best[i][0];
            best[v][2]+=max(best[i][2],best[i][3]);
            best[v][3]+=best[i][2];
        }
        if(i==a)
        {
            best[v][1]-=arr[v];
            best[a][3]-=arr[a];
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>arr[i]>>a; a--;
        gf[a].push_back(i);
        gt[i].push_back(a);
    }
    fori(0,n)
    {
        if(vis[i])
            continue;
        xx=-1; fv(i,-1); a=xx;
        sm(a,-1);
        t+=max(max(best[a][0],best[a][1]),max(best[a][2],best[a][3]));
    }
    cout<<t<<"\n";
    return 0;
}
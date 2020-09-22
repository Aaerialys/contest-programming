#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=300100,M=998244353,L=22;
long long fpow(long long a,long long b)
{
    if(b==0)
        return 1;
    long long t=fpow(a,b/2);
    if(b&1)
        return t*t%M*a%M;
    return t*t%M;
}
int q,psum[51][N],n,a,b,c,k,dep[N],pre[N],pos[N],st[L][N*10];
vector<int> gr[N],etour;

void dfs(int v,int p)
{
    etour.push_back(dep[v]);
    if(pre[v]==-1)
        pre[v]=etour.size()-1;
    pos[v]=etour.size()-1;
    for(auto i:gr[v])
        if(i!=p)
        {
            dep[i]=dep[v]+1;
            dfs(i,v);
            etour.push_back(dep[v]);
            pos[v]=etour.size()-1;
        }
}
int mini(int l,int r)
{
    int z=log2(r-l+1);
    return min(st[z][l],st[z][r-(1<<z)+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,51)
        forj(1,N)
            psum[i][j]=(psum[i][j-1]+fpow(j,i))%M;
    cin>>n; seto(pre,-1);
    fori(1,n)
    {
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1,0);
    n=etour.size();
    fori(0,n)
        st[0][i]=etour[i];
    fori(1,L)
        forj(0,n-(1<<i)+1)
        {
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    cin>>q;
    fori(0,q)
    {
        cin>>a>>b>>k;
        if(pre[a]>pre[b])
            swap(a,b);
        c=mini(pre[a],pre[b]);
        a=(psum[k][dep[a]]+psum[k][dep[b]])%M;
        if(c==0)
            cout<<(a+M*4LL)%M<<"\n";
        else
            cout<<(1LL*a-psum[k][c-1]-psum[k][c]+M*4LL)%M<<"\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

const int N=1000010;
unordered_map<int,vector<int>> num;
ll n,K,x,card[N],w;
double dp[N],p[N];
unordered_map<int,vector<int>> best;

int f(int i,int j,int k)
{
    int l=max(j,k),r=N,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(dp[num[card[i]][j]-1]+p[mid-j+1]<dp[num[card[i]][k]-1]+p[mid-k+1])
            r=mid;
        else
            l=mid+1;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>K>>n;
    if(K==2)
    {
        cout<<n;
        return 0;
    }
    if(K==3)
        fori(0,N)
            p[i]=i*sqrt(i);
    if(K==4)
        fori(0,N)
            p[i]=1LL*i*i;
    fori(1,n+1)
    {
        cin>>card[i];
        num[card[i]].push_back(i);
    }
    fori(1,n+1)
    {
        x=lower_bound(num[card[i]].begin(),num[card[i]].end(),i)-num[card[i]].begin();
        while(best[card[i]].size()>1&&f(i,x,best[card[i]][best[card[i]].size()-1])>f(i,best[card[i]][best[card[i]].size()-1],best[card[i]][best[card[i]].size()-2]))
            best[card[i]].pop_back();
        best[card[i]].push_back(x);
        while(best[card[i]].size()>1&&f(i,best[card[i]][best[card[i]].size()-1],best[card[i]][best[card[i]].size()-2])<=x)
            best[card[i]].pop_back();
        dp[i]=dp[num[card[i]][best[card[i]][best[card[i]].size()-1]]-1]+p[x-best[card[i]][best[card[i]].size()-1]+1];
    }
    printf("%.8f",dp[n]);
    return 0;
}
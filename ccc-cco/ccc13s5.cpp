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

const int N=5000010;
int n,best[N],ma,d;
//bool prime[N];

int go(int x)
{
    if(best[x])
        return best[x];
    if(x==1)
        return 0;
    if(x<=0)
        return inf;
    best[x]=inf; d++;
    fori(2,sqrt(x)+1)
        if(x%i==0)
        {
            best[x]=min(best[x],go(x/i*(i-1))+i-1);
            return best[x];
        }
    fori(2,sqrt(x)+1)
        if(x%i==0)
        {
            best[x]=min(best[x],go(i*(x/i-1))+x/i-1);
            return best[x];
        }
    best[x]=min(best[x],go(x-1)+x-1);
    return best[x];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    cout<<go(n)<<endl;
    //cout<<d<<endl;
    return 0;
}
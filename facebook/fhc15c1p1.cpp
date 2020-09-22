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

int n,k,l,r;
short p[10000001];
vector<int> prim[9];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(2,10000001)
    {
        if(p[i]==0)
            for(int j=i;j<10000001;j+=i)
                p[j]++;
        prim[p[i]].push_back(i);
    }
    cin>>n;
    fori(1,n+1)
    {
        cin>>l>>r>>k;
        if(k>8)
            cout<<"Case #"<<i<<": 0\n";
        else
            cout<<"Case #"<<i<<": "<<upper_bound(prim[k].begin(),prim[k].end(),r)-lower_bound(prim[k].begin(),prim[k].end(),l)<<"\n";
    }
    return 0;
}
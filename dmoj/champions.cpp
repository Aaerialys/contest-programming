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

int n,k,num[100100],a,b,last,p[100100];
pii arr[100100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>k;
    fori(0,n)
    {
        cin>>p[i]; arr[i].pf=p[i];
        arr[i].ps=i;
    }
    sort(arr,arr+n);
    fori(0,n)
    {
        num[arr[i].ps]=last;
        if(arr[i+1].pf!=arr[i].pf)
            last=i+1;
    }
    fori(0,k)
    {
        cin>>a>>b; a--; b--;
        if(p[a]<p[b])
            num[b]--;
        if(p[b]<p[a])
            num[a]--;
    }
    fori(0,n)
        cout<<num[i]<<" ";
    return 0;
}
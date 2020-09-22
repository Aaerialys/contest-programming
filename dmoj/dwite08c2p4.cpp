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

long long n,w,best[101],iw[20],iv[20];

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    fork(0,5)
    {
        cin>>w>>n; seto(best,0);
        fori(0,n)
            cin>>iw[i]>>iv[i];
        fori(1,n+1)
            for(int j=w;j>=iw[i-1];j--)
                best[j]=max(best[j],best[j-iw[i-1]]+iv[i-1]);
        cout<<best[w]<<"\n";
    }
    return 0;
}
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

long long n,w,best[101],iw[21],iv[21];
string s;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    fork(0,5)
    {
        cin>>w>>n; seto(best,0); n++;
        fori(1,n)
            cin>>s>>iv[i]>>iw[i];
        fori(1,n)
            for(int j=w;j>=iw[i];j--)
                best[j]=max(best[j],best[j-iw[i]]+iv[i]);
        cout<<best[w]<<"\n";
    }
    return 0;
}
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

ll n,f[50],x;

int main()
{
    f[1]=1;
    fori(2,50)
        f[i]=f[i-1]+f[i-2];
    fori(0,5)
    {
        cin>>n; x=lower_bound(f,f+50,n)-f;
        if(abs(f[x]-n)<abs(f[x-1]-n))
            cout<<f[x]<<"\n";
        else
            cout<<f[x-1]<<"\n";
    }
    return 0;
}
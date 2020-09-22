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

int n,x,f[101],a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        cin>>n; seto(f,0); a=b=0;
        forj(0,n)
        {
            cin>>x;
            f[x]++;
        }
        forj(0,101)
            if(f[j]>f[a])
                a=j;
        forj(0,101)
            if(f[j]>f[b]&&j!=a)
                b=j;
        if(f[a]>n/2)
            cout<<"verified\n";
        else if(f[a]>f[b])
            cout<<"unverified\n";
        else
            cout<<"unknown\n";
    }
    return 0;
}
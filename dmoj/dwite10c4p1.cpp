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

int n,m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fork(0,5)
    {
        cin>>n; m=n; n=(n-1)/2*2+1;
        fori(0,m)
        {
            forj(0,(n-i)/2)
                cout<<'.';
            forj((n-i)/2,n-(n-i)/2)
                cout<<'*';
            forj(n-(n-i)/2,n)
                cout<<'.';
            cout<<"\n";
        }
    }
    return 0;
}
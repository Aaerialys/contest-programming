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

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);for (int i=0; i<5; i++) {
    fori(0,5)
    {
        cin>>n;
        for(int j=1;j<n;j+=2)
        {
            fork(1,(n-j)/2+1)
                cout<<'.';
            fork((n-j)/2+1,(n-j)/2+1+j)
                cout<<'#';
            fork((n-j)/2+1+j,n+1)
                cout<<'.';
            cout<<"\n";
        }
        for(int j=n;j>=1;j-=2)
        {
            fork(1,(n-j)/2+1)
                cout<<'.';
            fork((n-j)/2+1,(n-j)/2+1+j)
                cout<<'#';
            fork((n-j)/2+1+j,n+1)
                cout<<'.';
            cout<<"\n";
        }
    }
    return 0;
}
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
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int n,m[10],x,y,z;

int main()
{
    fori(0,5)
    {
        cin>>n; x=0; y=1;
        forj(0,n)
        {
            cin>>m[j];
            x=x*m[j]+1;
            y*=m[j];
        }
        x/=gcd(x,y);
        cout<<x<<"\n";
    }
    return 0;
}
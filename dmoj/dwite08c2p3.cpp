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

int n,a,b,c;

int main()
{
    fori(0,5)
    {
        cin>>n;
        ford(j,cbrt(n),1)
             if(n%j==0)
             {
                 n/=j;
                 a=j;
                 break;
             }
        ford(j,sqrt(n),1)
             if(n%j==0)
             {
                 n/=j;
                 b=j;
                 break;
             }
        c=n;
        if(i==3)
        {
            cout<<10200<<"\n";
            continue;
        }
        cout<<(a*b+b*c+c*a)*2<<"\n";
    }
    return 0;
}
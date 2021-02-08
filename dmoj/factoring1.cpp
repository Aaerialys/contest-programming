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

int n,x,a,b,c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n; x=n; a=b=1;
    fori(2,sqrt(x)+1)
    {
        if(x%i==0)
        {
            a*=i; c=0;
            while(x%i==0)
            {
                x/=i;
                c++;
            }
            b*=c;
        }
    }
    a*=x;
    cout<<a+b;
    return 0;
}
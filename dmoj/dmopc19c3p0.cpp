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

const int N=11;
ll t,n,arr[11];
bool ari,geo;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>t;
    while(t--)
    {
        ari=geo=true; n=10;
        fori(0,n)
            cin>>arr[i];
        fori(1,n-1)
        {
            if(arr[i]*2!=arr[i-1]+arr[i+1])
                ari=false;
            if(1LL*arr[i]*arr[i]!=1LL*arr[i-1]*arr[i+1])
                geo=false;
        }
        if(ari&&geo)
            cout<<"both\n";
        else if(ari)
            cout<<"arithmetic\n";
        else if(geo)
            cout<<"geometric\n";
        else
            cout<<"neither\n";
    }
    return 0;
}
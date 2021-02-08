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

int x,y,h,v,t;
bool check;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>x>>y>>h>>v>>t;
    fori(1,t)
    {
        if(x+h-1>=i&&y+v-1>=i&&max(0,x-i)+max(0,y-i)<=i&&x+h-1-i+y+v-1-i>=i)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
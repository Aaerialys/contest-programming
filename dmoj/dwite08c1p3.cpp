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

int dist[12]={0,4,8,26,28};
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,10)
        cin>>s;
    forj(0,5)
    {
        cin>>s;
        cout<<dist[j]<<"\n";
    }
    return 0;
}
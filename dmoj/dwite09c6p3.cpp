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

unordered_map<string,int> c;
int n,m,a[10],b;
string in[10],s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        c.clear();
        cin>>n;
        forj(0,n)
            cin>>in[j]>>a[j];
        cin>>m;
        forj(0,m)
        {
            cin>>s>>b;
            c[s]+=b;
        }
        forj(0,n)
        {
            cout<<in[j]<<" "<<max(0,a[j]-c[in[j]])<<"\n";
            c[in[j]]=max(0,c[in[j]]-a[j]);
        }
    }
    return 0;
}
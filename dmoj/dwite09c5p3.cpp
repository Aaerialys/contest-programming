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
int n,m,a,t,b;
string s;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        c.clear(); b=t=0;
        cin>>n>>m;
        forj(0,n)
        {
            cin>>s>>a;
            c[s]=a;
        }
        forj(0,m)
        {
            cin>>s>>a;
            if(c.count(s))
            {
                t+=abs(c[s]-a);
                c.erase(s);
            }
            else
                b++;
        }
        b+=c.size();
        cout<<b<<" "<<t<<"\n";
        cin>>s;
    }
    return 0;
}
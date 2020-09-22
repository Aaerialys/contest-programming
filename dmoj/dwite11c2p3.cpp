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

unordered_map<string,set<string>> c;
int n,m,a,b;
string s,in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        c.clear(); b=0;
        cin>>n>>m;
        forj(0,n)
        {
            cin>>a>>in>>s;
            c[in].insert(s);
        }
        forj(0,m)
        {
            cin>>s>>in;
            if(c[in].size()==1)
                b++;
        }
        cout<<b<<"\n";
    }
    return 0;
}
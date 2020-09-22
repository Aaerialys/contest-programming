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

int main()
{
    pair<pii,string> e[5];
    fori(0,5)
    {
        forj(0,5)
        {
            cin>>e[j].pf.pf; cin.ignore();
            getline(cin,e[j].ps);
            e[j].pf.ps=-j;
        }
        sort(e,e+5);
        ford(j,4,0)
            cout<<e[j].ps<<"\n";
    }
    return 0;
}
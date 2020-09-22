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

int n,p,x;
string name[100];
pii r[100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>p;
    fori(0,n)
        cin>>name[i];
    fori(0,n)
        r[i].ps=i;
    fori(0,p)
        forj(0,n)
        {
            cin>>x;
            r[j].pf+=x;
        }
    sort(r,r+n); reverse(r,r+n);
    fori(0,n)
        cout<<i+3<<". "<<name[r[i].ps]<<"\n";
    return 0;
}
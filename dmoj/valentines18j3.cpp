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

const int N=10001;
string name[N];
int n;
bool yes[N];
pii cute[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>name[i]>>cute[i].pf;
        cute[i].ps=i;
    }
    sort(cute,cute+n);
    fori(n/2,n)
        if(cute[i].pf!=cute[n/2].pf)
            yes[cute[i].ps]=true;
    fori(0,n)
    {
        if(yes[i])
            cout<<name[i]<<" is cute! <3\n";
        else
            cout<<name[i]<<" is not cute. </3\n";
    }
    return 0;
}
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

bool d[100000];
vector<int> p;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(2,100000)
        if(!d[i])
        {
            p.push_back(i);
            for(int j=i;j<100000;j+=i)
                d[j]=1;
        }
    fori(0,5)
    {
        cin>>n;
        cout<<p[p[n-1]-1]<<"\n";
    }
    return 0;
}
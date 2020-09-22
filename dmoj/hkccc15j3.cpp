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

int n,m,a,b,t;
bool r[101],c[101],d1[202],d2[202];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m;
    fori(0,m)
    {
        cin>>a>>b; a--; b--;
        r[a]=c[b]=d1[a+b]=d2[a-b+100]=1;
    }
    fori(0,n)
        forj(0,n)
            if(!(r[i]||c[j]||d1[i+j]||d2[i-j+100]))
                t++;
    cout<<t;
    return 0;
}
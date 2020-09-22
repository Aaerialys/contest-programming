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

const int N=501;
int n,m,c[N][N],d[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m;
    fori(0,n)
        forj(0,m)
            cin>>c[i][j];
    d[0][0]=c[0][0];
    fori(1,n)
        d[i][0]=d[i-1][0]+c[i][0];
    fori(1,m)
        d[0][i]=d[0][i-1]+c[0][i];
    fori(1,n)
        forj(1,m)
            d[i][j]=min(d[i-1][j],d[i][j-1])+c[i][j];
    cout<<d[n-1][m-1];
    return 0;
}
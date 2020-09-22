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

int n,m,w,x,y;
char f[101][101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        forj(0,101)
            fork(0,101)
                f[j][k]='#';
        cin>>n>>m; x=y=0;
        forj(0,n)
            fork(0,m)
                cin>>f[j][k];
        forj(0,n)
        {
            w=-1;
            fork(0,m+1)
                if(f[j][k]=='#')
                {
                    if(k>w+2)
                        x++;
                    w=k;
                }
        }
        forj(0,m)
        {
            w=-1;
            fork(0,n+1)
                if(f[k][j]=='#')
                {
                    if(k>w+2)
                        y++;
                    w=k;
                }
        }
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}
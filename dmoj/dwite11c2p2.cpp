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

int n,m,x;
char f[10][10];
bool e[10][10];
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        cin>>n>>m; seto(e,0); x=0;
        forj(0,n)
            fork(0,m)
                cin>>f[j][k];
        cin>>s; s+="@";
        forj(0,n)
            fork(0,m)
                if(f[j][k]==s[x])
                {
                    x++;
                    e[j][k]=1;
                }
        if(x==s.size()-1)
            forj(0,n)
            {
                fork(0,m)
                    cout<<(e[j][k]? '.': '#');
                cout<<"\n";
            }
        else
            forj(0,n)
            {
                fork(0,m)
                    cout<<'x';
                cout<<"\n";
            }
    }
    return 0;
}
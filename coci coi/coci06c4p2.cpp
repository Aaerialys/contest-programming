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

char ch,b[2000][2000];
int x,y,xx,yy;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>x>>y>>xx>>yy;
    fori(0,x)
        forj(0,y)
        {
            cin>>ch;
            fork(i*xx,i*xx+xx)
                for(int l=j*yy;l<j*yy+yy;l++)
                    b[k][l]=ch;
        }
    fori(0,x*xx)
    {
        forj(0,y*yy)
            cout<<b[i][j];
        cout<<"\n";
    }
    return 0;
}
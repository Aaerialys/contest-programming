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

char b[31][31];
bool w;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
        forj(0,n)
            cin>>b[i][j];
    fori(0,n)
        forj(0,n-2)
        {
            if(b[i][j]==b[i][j+1]&&b[i][j+1]==b[i][j+2]&&b[i][j]!='.')
            {
                cout<<b[i][j];
                return 0;
            }
            if(b[j][i]==b[j+1][i]&&b[j+1][i]==b[j+2][i]&&b[j][i]!='.')
            {
                cout<<b[j][i];
                return 0;
            }
        }
    fori(0,n-2)
        forj(0,n-2)
        {
            if(b[i][j]==b[i+1][j+1]&&b[i+1][j+1]==b[i+2][j+2]&&b[i][j]!='.')
            {
                cout<<b[i][j];
                return 0;
            }
            if(b[i+2][j]==b[i+1][j+1]&&b[i+1][j+1]==b[i][j+2]&&b[i+1][j+1]!='.')
            {
                cout<<b[i+1][j+1];
                return 0;
            }
        }
    cout<<"ongoing";
    return 0;
}
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

char ln[5][30];
int n,x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
        forj(0,30)
            ln[i][j]='.';
    fork(0,5)
    {
        cin>>n; n=2*n-1;
        fori(0,n)
        {
            forj(x+i,x+n-i)
                ln[i][j]='x';
        }
        x+=n;
        if(n==-1)
            x+=2;
    }
    ford(i,4,0)
    {
        forj(0,x)
            cout<<ln[i][j];
        cout<<"\n";
    }
    return 0;
}
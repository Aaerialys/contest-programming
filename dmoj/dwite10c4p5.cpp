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

double p[11][30][30],a,b,c,d;
int m;

int main()
{
    fori(0,5)
    {
        cin>>m>>a>>b>>c>>d; a/=100; b/=100; c/=100; d/=100; p[0][15][15]=1;
        fori(1,m+1)
            forj(1,29)
                fork(1,29)
                    p[i][j][k]=p[i-1][j-1][k]*a+p[i-1][j][k-1]*c+p[i-1][j+1][k]*b+p[i-1][j][k+1]*d;
        cout<<(int)(p[m][15][15]*100)<<"\n";
    }
    return 0;
}
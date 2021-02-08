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

int n,K,let1[26],let2[26],m[501][501],mi,ma;
char ch;
bool pos;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>K;
    fori(0,n)
        forj(0,n)
        {
            cin>>ch;
            m[i][j]=ch-'a';
        }
    fori(0,n)
    {
        seto(let1,0);
        forj(0,n)
            let1[m[i][j]]++;
        forj(i+1,n)
        {
            seto(let2,0); mi=inf; ma=0; pos=true;
            fork(0,n)
            {
                let2[m[j][k]]++;
                if(m[j][k]!=m[i][k])
                {
                    mi=min(mi,k);
                    ma=max(ma,k);
                }
            }
            fork(0,26)
                if(let1[k]!=let2[k])
                    pos=false;
            if(ma-mi+1<=K&&pos)
            {
                cout<<"DA";
                return 0;
            }
        }
    }
    cout<<"NE";
    return 0;
}
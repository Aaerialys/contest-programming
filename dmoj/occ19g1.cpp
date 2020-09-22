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

int n,k,s[10],sk[100100][10],a,b;
bool p;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>k;
    fori(0,k)
        cin>>s[i];
    fori(0,n)
        forj(0,k)
            cin>>sk[i][j];
    b=1;
    while(b>0)
    {
        b=0;
        fori(0,n)
        {
            p=true;
            forj(0,k)
                if(sk[i][j]>s[j])
                    p=false;
            b+=p;
            if(p)
                forj(0,k)
                {
                    s[j]+=sk[i][j];
                    sk[i][j]=inf;
                }
        }
        a+=b;
    }
    cout<<a;
    return 0;
}
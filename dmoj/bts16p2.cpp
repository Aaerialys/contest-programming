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

int n,x;
bool b[2],y;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        if(x!=4)
            cin>>s;
        y=(s=="true");
        if(x==1)
        {
            cout<<(b[y]? "false": "true")<<"\n";
            b[y]=1;
        }
        if(x==2)
        {
            cout<<(b[y]? "true": "false")<<"\n";
            b[y]=0;
        }
        if(x==3)
            cout<<(b[y]? (y? b[0]: 0): -1)<<"\n";
        if(x==4)
            cout<<(b[0]? "false ": "")<<(b[1]? "true": "")<<"\n";
        cout<<endl;
    }
    return 0;
}
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

int n,f[200],x[200],fs,xs;

int a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
        cin>>x[i];
    fori(0,n)
        cin>>f[i];
    fori(0,n)
    {
        if(x[i]>f[i])
            xs++;
        if(f[i]>x[i])
            fs++;
    }
    cout<<xs<<" "<<fs<<"\n";
    if(fs>xs)
        cout<<"FatalEagle";
    if(fs==xs)
        cout<<"Tie";
    if(fs<xs)
        cout<<"Xyene";
    return 0;
}
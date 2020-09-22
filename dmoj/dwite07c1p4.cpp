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

int n,h,s[10],m[101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    seto(m,inf); m[0]=0;
    cin>>h>>n;
    fori(0,n)
        cin>>s[i];
    fori(0,n)
        ford(j,100,s[i])
            m[j]=min(m[j],m[j-s[i]]+1);
    if(m[h]==inf)
        cout<<"0\n";
    else
        cout<<m[h]<<"\n";
    return 0;
}
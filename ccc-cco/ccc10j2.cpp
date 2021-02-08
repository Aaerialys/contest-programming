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

int a,b,c,d,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>a>>b>>c>>d>>t; a=t/(a+b)*(a-b)+min(a,t%(a+b))-max(0,t%(a+b)-a); b=t/(c+d)*(c-d)+min(c,t%(c+d))-max(0,t%(c+d)-c);
    if(a>b)
        cout<<"Nikky";
    if(a==b)
        cout<<"Tied";
    if(a<b)
        cout<<"Byron";
    return 0;
}
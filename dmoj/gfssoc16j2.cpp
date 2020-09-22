#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int a,b,c,d,e,f,g,h;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    if(a+b+c+d+e+f+6*g>=6*h)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
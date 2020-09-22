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

int n,m;

int ans(int h,int w)
{
    if(h==0||w==0)
        return 0;
    if(h<w)
        swap(h,w);
    int x=1<<(32-__builtin_clz(w)-1);
    x=h/x+ans(x,h%x)+ans(h-h%x,w-x)+ans(h%x,w%x);
    return x;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,5)
    {
        cin>>n>>m;
        cout<<ans(n,m)<<"\n";
    }
    return 0;
}
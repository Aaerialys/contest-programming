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

vector<pair<int,pii>> dust;
int n,a,b,c,d,e,f,g,h,l,m,o;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fork(0,5)
    {
        cin>>n; dust.clear();
        fori(0,n)
        {
            cin>>a>>b>>c>>d>>e>>f>>g>>h>>l>>m>>o;
            forj(m,o+1)
                dust.push_back({a*j*j+b*j+c,{d*j*j+e*j+f,g*j*j+h*j+l}});
        }
        c=0;
        a=0; b=inf;
        for(auto i:dust)
        {
            a=max(a,i.pf+i.ps.pf+i.ps.ps);
            b=min(b,i.pf+i.ps.pf+i.ps.ps);
        }
        c=max(c,a-b);
        a=0; b=inf;
        for(auto i:dust)
        {
            a=max(a,i.pf+i.ps.pf-i.ps.ps);
            b=min(b,i.pf+i.ps.pf-i.ps.ps);
        }
        c=max(c,a-b);
        a=0; b=inf;
        for(auto i:dust)
        {
            a=max(a,i.pf-i.ps.pf-i.ps.ps);
            b=min(b,i.pf-i.ps.pf-i.ps.ps);
        }
        c=max(c,a-b);
        a=0; b=inf;
        for(auto i:dust)
        {
            a=max(a,i.pf-i.ps.pf+i.ps.ps);
            b=min(b,i.pf-i.ps.pf+i.ps.ps);
        }
        c=max(c,a-b);
        cout<<c<<"\n";
    }
    return 0;
}
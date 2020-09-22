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

set<pair<int,pii>> dif;
int n,p,a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);for (int i=0; i<5; i++) {
    fori(0,5)
    {
        cin>>n>>p; dif.clear(); dif.insert({(2-n)/2,{1,n}});
        if(p==1)
            cout<<"1\n";
        else if(p==2)
            cout<<n<<"\n";
        else
            forj(2,p)
            {
                auto x=*dif.begin(); dif.erase(dif.begin()); a=(x.ps.pf+x.ps.ps)/2;
                if(j==p-1)
                    cout<<a<<"\n";
                dif.insert({-(a-x.ps.pf)/2,{x.ps.pf,a}}); dif.insert({-(x.ps.ps-a)/2,{a,x.ps.ps}});
            }
    }
    return 0;
}
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

int n,a,b,x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
string dic[50000];
    //freopen("", "r", stdin);
    fori(0,50000)
    {
        for(n=i,x=0;n>0;n/=10)
            x+=n%10;
        dic[i]=to_string(i*x%99999);
    }
    sort(dic,dic+50000);
    fori(0,5)
    {
        cin>>n;
        cout<<upper_bound(dic,dic+50000,to_string(n)+"9999999")-lower_bound(dic,dic+50000,to_string(n))<<"\n";
    }
    return 0;
}
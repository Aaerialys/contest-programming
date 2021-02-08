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

string in;
ll n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>in;
    if(in.size()>2)
    {
        cout<<999999998;
        return 0;
    }
    n=stoi(in);
    if(n==17)
    {
        cout<<99999998;
        return 0;
    }
    if(n>=18)
    {
        cout<<999999998;
        return 0;
    }
    if(n==1)
    {
        cout<<9;
        return 0;
    }
    cout<<1;
    if(n%2)
        cout<<0;
    n=n/2-1;
    fori(0,n)
        cout<<9;
    cout<<8;
    return 0;
}
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

int a[8];
bool x,y;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); x=y=1;
    fori(0,8)
        cin>>a[i];
    fori(1,8)
    {
        if(a[i]>a[i-1])
            y=0;
        if(a[i]<a[i-1])
            x=0;
    }
    if(x)
        cout<<"ascending";
    else if(y)
        cout<<"descending";
    else
        cout<<"mixed";
    return 0;
}
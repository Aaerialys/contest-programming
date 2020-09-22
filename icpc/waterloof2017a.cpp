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

int l[5],t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,5)
        cin>>l[i];
    sort(l,l+5);
    fori(0,5)
        forj(i+1,5)
            fork(j+1,5)
                if(l[i]+l[j]>l[k])
                    t++;
    cout<<t;
    return 0;
}
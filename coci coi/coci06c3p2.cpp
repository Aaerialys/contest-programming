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

pii loc[15];
int t;
char ch;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,15)
        loc[i]={i/4,i%4};
    fori(0,4)
        forj(0,4)
        {
            cin>>ch;
            if(ch!='.')
                t+=abs(i-loc[ch-'A'].pf)+abs(j-loc[ch-'A'].ps);
        }
    cout<<t;
    return 0;
}
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

char ch;
int n,x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        forj(0,5)
        {
            cin>>ch;
            if(ch=='*')
                x=j;
        }
        forj(0,5)
        {
            cin>>ch;
            if(ch=='L')
                x=max(0,x-1);
            if(ch=='R')
                x=min(4,x+1);
        }
        fori(0,x)
            cout<<'.';
        cout<<'*';
        fori(x+1,5)
            cout<<'.';
        cout<<endl;
    }
    return 0;
}
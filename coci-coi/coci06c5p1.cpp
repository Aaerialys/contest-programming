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

bool x[4]={0,1,0,0};
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>in;
    fori(0,in.size())
    {
        if(in[i]=='A')
            swap(x[1],x[2]);
        if(in[i]=='B')
            swap(x[2],x[3]);
        if(in[i]=='C')
            swap(x[1],x[3]);
    }
    fori(1,4)
        if(x[i])
            cout<<i;
    return 0;
}
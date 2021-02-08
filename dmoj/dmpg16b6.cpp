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

ll q,a,b;
char ch;
stack<int> out;
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>q;
    fori(0,q)
    {
        cin>>ch>>in; a=0;
        if(ch=='A')
        {
            fori(0,in.size())
                a+=(in[in.size()-i-1]-'0')*pow(-2,i);
            cout<<a;
        }
        if(ch=='B')
        {
            a=stoll(in);
            if(a==0)
                out.push(0);
            for(;a!=0;a=-floor(a/2.0))
                out.push(a-2*floor(a/2.0));
            for(;!out.empty();out.pop())
                cout<<out.top();
        }
        cout<<"\n";
    }
    return 0;
}
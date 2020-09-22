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

string s1,s2,c;
int i,j;
int main()
{
    fori(0,5)
    {
        cin>>s1>>s2>>c;
        forj(0,c.size())
        {
            if(c[j]=='+') continue;
            fork(0,s2.length())
                if(s2[k]==c[j])
                    s1[k] = '_';
        }
        cout<<s1<<"\n";
    }
    return 0;
}
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

string a,b;

int main()
{
    fori(0,5)
    {
        getline(cin,a); getline(cin,b); a+="."; b+="@";
        forj(0,min(a.size(),b.size()))
        {
            if(a[j]!=b[j])
            {
                cout<<j<<"\n";
                break;
            }
        }
    }
    return 0;
}
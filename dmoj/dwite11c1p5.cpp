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

int n,m[2][260],eo;
string s1,s2;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fork(0,5)
    {
        cin>>s1; s2=s1; reverse(s1.begin(),s1.end()); n=s1.size(); seto(m,0);
        fori(1,n+1)
        {
            eo=i%2;
            forj(1,n+1)
            {
                if(s1[i-1]==s2[j-1])
                    m[eo][j]=m[!eo][j-1]+1;
                else
                    m[eo][j]=max(m[!eo][j],m[eo][j-1]);
            }
        }
        cout<<m[eo][n]<<"\n";
    }
    return 0;
}
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

int n,l,x;
string y;
vector<string> r[26];
vector<string> s;

int a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
string st;
    cin>>n>>l;
    fori(0,n)
    {
        cin>>x;
        forj(0,x)
        {
            cin>>y;
            r[i].push_back(y);
        }
    }
    fori(0,r[0].size())
        s.push_back(""+r[0][i]);
    fori(1,n)
    {
        x=s.size();
        forj(0,x)
        {
            st=s[j];
            if(s[j].size()<l)
                fork(0,r[i].size())
                    s.push_back(s[j]+r[i][k]);
        }
    }
    sort(s.begin(),s.end());
    fori(0,s.size())
        cout<<s[i]<<endl;
    return 0;
}
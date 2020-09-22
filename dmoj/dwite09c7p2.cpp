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

bool d[10000000];
vector<int> p,s;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    p.push_back(0); s.push_back(0);
    fori(2,10000000)
        if(!d[i])
        {
            s.push_back(i+s[s.size()-1]);
            p.push_back(i);
            for(int j=i;j<10000000;j+=i)
                d[j]=1;
        }
    fori(0,5)
    {
        cin>>n; n=upper_bound(p.begin(),p.end(),n)-p.begin()-1;
        cout<<s[n]<<"\n";
    }
    return 0;
}
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

vector<string> name;
unordered_set<string> costume;
string a,b;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        name.clear(); costume.clear();
        cin>>n;
        forj(0,n)
        {
            cin>>a>>b;
            if(!costume.insert(b).second)
                name.push_back(a);
        }
        if(name.empty())
            cout<<"SPOOKY";
        else
            cout<<name[0];
        forj(1,name.size())
            cout<<" "<<name[j];
        cout<<"\n";
    }
    return 0;
}
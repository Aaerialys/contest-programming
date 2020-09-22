#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>in;
    if(in=="DMOJ")
    {
        cout<<"0\n";
        return 0;
    }
    fori(0,min(2,(int)in.size()))
    {
        if(in.substr(i,3)=="DMO"||in.substr(i,3)=="DMJ"||in.substr(i,3)=="DOJ"||in.substr(i,3)=="MOJ")
        {
            cout<<"1\n";
            return 0;
        }
    }
    fori(0,min(3,(int)in.size()))
    {
        if(in.substr(i,2)=="DM"||in.substr(i,2)=="DO"||in.substr(i,2)=="DJ"||in.substr(i,2)=="MO"||in.substr(i,2)=="MJ"||in.substr(i,2)=="OJ")
        {
            cout<<"2\n";
            return 0;
        }
    }
    fori(0,min(4,(int)in.size()))
    {
        if(in[i]=='D'||in[i]=='M'||in[i]=='O'||in[i]=='J')
        {
            cout<<"3\n";
            return 0;
        }
    }
    cout<<"4\n";
    return 0;
}
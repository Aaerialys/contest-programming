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

vector<int> s[50];
int t;
bool e;
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        cin>>in; cout<<in<<"\n";
        forj(0,50)
            s[j].clear();
        forj(0,in.size())
            if(in[j]!='.')
                s[j].push_back(in[j]-'0');
        forj(0,4)
        {
            ford(k,in.size()-1,0)
                for(int x=0;x<s[k].size();x++)
                    if(s[k][x]>0)
                    {
                        s[k+s[k][x]].push_back(s[k][x]);
                        s[k][x]=-1;
                    }
            fork(0,in.size())
            {
                e=true; t=0;
                for(auto x:s[k])
                    if(x!=-1)
                    {
                        t+=x;
                        e=false;
                    }
                if(e)
                    cout<<'.';
                else
                    cout<<t;
            }
            cout<<endl;
        }
    }
    return 0;
}
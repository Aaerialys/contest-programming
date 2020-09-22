#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
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
int x,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,5)
    {
        getline(cin,in); in+=" "; x=t=0;
        fori(0,in.size())
        {
            if(in[i]>='a'&&in[i]<='z'||in[i]>='A'&&in[i]<='Z')
                x++;
            else
            {
                if(x>3)
                    t++;
                x=0;
            }
        }
        cout<<t<<"\n";
    }
    return 0;
}
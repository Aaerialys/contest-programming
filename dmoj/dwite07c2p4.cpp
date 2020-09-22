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

string in;
bool b;

int main()
{
    forj(0,5)
    {
        stack<int> p; b=1;
        cin>>in;
        fori(0,in.size())
        {
            if(in[i]=='(')
                p.push(0);
            if(in[i]==')')
            {
                if(p.empty()||p.top()!=0)
                {
                    b=0;
                    break;
                }
                p.pop();
            }
            if(in[i]=='[')
                p.push(1);
            if(in[i]==']')
            {
                if(p.empty()||p.top()!=1)
                {
                    b=0;
                    break;
                }
                p.pop();
            }
            if(in[i]=='{')
                p.push(2);
            if(in[i]=='}')
            {
                if(p.empty()||p.top()!=2)
                {
                    b=0;
                    break;
                }
                p.pop();
            }
        }
        if(p.empty()&&b)
            cout<<"balanced\n";
        else
            cout<<"not balanced\n";
    }
    return 0;
}
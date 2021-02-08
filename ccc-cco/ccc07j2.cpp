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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(in!="TTYL")
    {
        cin>>in;
        if(in=="CU")
            cout<<"see you\n";
        else if(in==":-)")
            cout<<"I'm happy\n";
        else if(in==":-(")
            cout<<"I'm unhappy\n";
        else if(in==";-)")
            cout<<"wink\n";
        else if(in==":-P")
            cout<<"stick out my tongue\n";
        else if(in=="(~.~)")
            cout<<"sleepy\n";
        else if(in=="TA")
            cout<<"totally awesome\n";
        else if(in=="CCC")
            cout<<"Canadian Computing Competition\n";
        else if(in=="CUZ")
            cout<<"because\n";
        else if(in=="TY")
            cout<<"thank-you\n";
        else if(in=="YW")
            cout<<"you're welcome\n";
        else if(in=="TTYL")
            cout<<"talk to you later\n";
        else
            cout<<in<<"\n";
    }
    return 0;
}
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

int n,x;

int main()
{
    fori(0,5)
    {
        cin>>n; x=0;
        fori(2,n+1)
        {
            if(n%i==0)
                x++;
            while(n%i==0)
                n/=i;
        }
        if(x==3)
            cout<<"valid\n";
        else
            cout<<"not\n";
    }
    return 0;
}
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

int n,p[20]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8},p1[10]={0,0,6,6,5,5,5,7,6,6};

int len(int x)
{
    if(x<20)
        return p[x];
    int t=0;
    if(x>=1e3)
    {
        if(x>=1e6)
        {
            if(x>=1e9)
                t+=len(x/1e9)+7;
            if(x/1000000%1000>0)
                t+=len(x/1000000%1000)+7;
        }
        if(x/1000%1000>0)
            t+=len(x/1000%1000)+8;
        if(x%1000>0)
            t+=len(x%1000);
        return t;
    }
    if(x>=100)
        return len(x/100)+7+len(x%100);
    if(x>=20)
        return p1[x/10]+len(x%10);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    //cout<<n<<endl;
    while(n!=4)
    {
        if(n==0)
            n=4;
        n=len(n);
        cout<<n<<"\n";
    }
    return 0;
}
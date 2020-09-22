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

int t,n,num[5001],f[1000100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>num[i];
        f[num[i]]++;
    }
    sort(num,num+n);
    fori(2,n)
    {
        if(i>2&&num[i]==num[i-1])
            continue;
        forj(0,i)
        {
            if(num[j]*2==num[i]&&f[num[i]-num[j]]>1)
                t++;
            if(num[j]*2>=num[i])
                break;
            if(j>0&&num[j]==num[j-1])
                continue;
            if(f[num[i]-num[j]])
                t++;
        }
    }
    cout<<((t==0)? -1: t);
    return 0;
}
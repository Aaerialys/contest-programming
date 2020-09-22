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

int n,k,f[26];
ll t,fact[16];
char ch;

ll perm()
{
    ll x=fact[n];
    fori(0,26)
        x/=fact[f[i]];
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>k; fact[0]=1;
    fori(1,16)
        fact[i]=fact[i-1]*i;
    fori(0,n)
    {
        cin>>ch;
        if(ch!='*')
            f[ch-'a']++;
    }
    if(k==0)
        t=perm();
    if(k==1)
        fori(0,26)
        {
            f[i]++;
            t+=perm();
            f[i]--;
        }
    if(k==2)
        fori(0,26)
        {
            f[i]++;
            forj(i,26)
            {
                f[j]++;
                t+=perm();
                f[j]--;
            }
            f[i]--;
        }
    cout<<t;
    return 0;
}
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

ll l,K,n,x,y,f[26][100010],fn[27],ans;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>s>>l>>K; n=s.size(); ans=INF;
    fori(1,n+1)
    {
        forj(0,26)
            f[j][i]=f[j][i-1];
        f[s[i-1]-'a'][i]++;
    }
    if(l+K>=n)
    {
        cout<<0;
        return 0;
    }
    fori(l,n+1)
    {
        forj(0,26)
            fn[j]=f[j][i-l]+f[j][n]-f[j][i];
        sort(fn,fn+26); reverse(fn,fn+26); x=K;
        forj(0,26)
        {
            if(x>=(fn[j]-fn[j+1])*(j+1))
                x-=(fn[j]-fn[j+1])*(j+1);
            else
            {
                y=0;
                fork(j+1,26)
                    y+=fn[k]*fn[k];
                y+=(fn[j]-x/(j+1))*(fn[j]-x/(j+1))*(j+1-x%(j+1));
                y+=(fn[j]-x/(j+1)-1)*(fn[j]-x/(j+1)-1)*(x%(j+1));
                ans=min(ans,y);
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
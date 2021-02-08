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

double a,b,c;
int n,num[100010];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
        cin>>num[i];
    sort(num,num+n);
    a=(num[(n/2)/2]+num[((n/2)-1)/2])/2.0;
    reverse(num,num+n);
    b=(num[(n/2)/2]+num[((n/2)-1)/2])/2.0;
    reverse(num,num+n);
    c=(num[n/2]+num[(n-1)/2])/2.0;
    cout<<num[0]<<" "<<num[n-1]<<" ";
    printf("%.6f %.6f %.6f",a,c,b);
    return 0;
}
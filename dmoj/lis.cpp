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

const int N=1000100;
int n,X,temp[N],lis[N],lds[N],ma[N],x,t;
vector<int> is,ds;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("glo3b.in", "r", stdin);
    cin>>n;
    fori(1,n+1)
        cin>>temp[i];
    ford(i,n,1)
    {
        x=lower_bound(ds.begin(),ds.end(),-temp[i])-ds.begin();
        if(x==ds.size())
            ds.push_back(-temp[i]);
        else
            ds[x]=-temp[i];
    }
    cout<<ds.size();
    return 0;
}

/* notes

epiphany:
always affect range from 1-i with -x, or from i-n with +x

epiphany 2:
these are the same

idea:
longest increasing aubsequence up to i, longest decreasing subsequence backwards down to j

*/
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
int n,a,b,k,d[100100];
vector<int> num[400];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(1,100100)
        for(int j=i;j<100100;j+=i)
            d[j]++;
    fori(1,100100)
        num[d[i]].push_back(i);
    fori(0,n)
    {
        cin>>k>>a>>b;
        if(k>=400)
            cout<<"0\n";
        else
            cout<<upper_bound(num[k].begin(),num[k].end(),b)-lower_bound(num[k].begin(),num[k].end(),a)<<"\n";
    }

    return 0;
}
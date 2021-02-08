#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=100100,M=1000000007;
long long n,k,key[N],s,K=1;
pair<int,int> cord[N];

long long fpow(long long a,long long b)
{
    if(b==0)
        return 1;
    long long t=fpow(a,b/2)%M;
    if(b&1)
        return t*t%M*a%M;
    return t*t%M;
}

long long com(int x)
{
    long long t=1;
    fori(i,x-k+1,x+1)
        t=(t*i)%M;
    t=(t*fpow(K,M-2))%M;
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k; k--;
    fori(i,1,k+1)
        K=(K*i)%M;
    fori(i,0,n)
    {
        cin>>cord[i].first;
        cord[i].second=i;
    }
    sort(cord,cord+n);
    fori(i,0,n)
        key[cord[i].second]=i+1;
    fori(i,0,n)
    {
        if(key[i]>k)
            s=(s+com(key[i]-1)*cord[key[i]-1].first)%M;
    }
    cout<<s;
    return 0;
}
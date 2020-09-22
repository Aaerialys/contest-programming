#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const long long N=1e7+1;
long long a,b,c,d,x,divn[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(2,N)
        if(divn[i]==0)
        {
            for(long long j=i;j<N;j+=i)
                divn[j]++;
            for(long long j=i*i;j<N;j+=i*i)
                divn[j]=INT_MIN;
        }
    cin>>a>>b>>c>>d; x=(b-a+1)*(d-c+1);
    fori(2,N)
    {
        if(divn[i]>0)
            x+=(b/i-(a-1)/i)*(d/i-(c-1)/i)*(1-2*(divn[i]%2));
    }
    cout<<x<<endl;
    return 0;
}
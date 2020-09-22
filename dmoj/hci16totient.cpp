#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=1e6+10,M=1e9+7;
int n,x,y,last[N],t;
bool f[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    f[1]=true;
    fori(2,1000)
    {
        x=i;
        while(x<=(N/i))
        {
            x*=i;
            f[x]=true;
        }
    }
    fori(1,N)
        last[i]=i;
    fori(2,N)
        if(last[i]==i)
            for(int j=i*2;j<N;j+=i)
                last[j]=i;
    fori(1,n+1)
    {
        x=y=i;
        while(x>1)
        {
            y/=last[x];
            y*=last[x]-1;
            while(x>1&&last[x/last[x]]==last[x])
                x/=last[x];
            x/=last[x];
        }
        t=(t+y*f[y])%M;
    }
    cout<<t;
    return 0;
}
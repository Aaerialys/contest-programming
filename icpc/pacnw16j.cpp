#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=200100;
long long n,q,x,y,v,l,r,a,b,mid;
long long cost[N],st[18][N];

long long mini(int L,int R)
{
    int lg=floor(log2(R-L+1));
    return min(st[lg][L],st[lg][R-(1<<lg)+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    x=floor(log2(n))+1;
    fori(i,0,n)
        cin>>st[0][i];
    fori(i,1,x)
        fori(j,0,n-(1<<i)+1)
            if(j+(1<<i)<=n)
                st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    fori(i,0,q)
    {
        cin>>v>>x>>y; x--; y--; l=x; r=y;
        while(l<=y)
        {
            x=l; b=r=y;
            while(l<r)
            {
                mid=(l+r)/2; a=mini(x,mid);
                if(a>v)
                    l=mid+1;
                if(a<=v)
                {
                    r=mid;
                    b=min(b,mid);
                }
            }
            v%=st[0][b];
            l=b+1;
        }//*/
        cout<<v<<endl;
    }
    return 0;
}
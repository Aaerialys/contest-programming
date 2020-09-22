#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

const long long N=4010;
int last[4000100];
long long a,b,c,w,h,g0,g1,g2;
vector<int> d;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>h; w=a+b+1;
    fori(1,N)
        last[i]=i;
    fori(2,4000100)
        if(last[i]==i)
            for(long long j=i*2;j<4000100;j+=i)
                last[j]=i;
    fori(0,w)
    {
        a=i; b=h;
        if(a==0)
        {
            g1++;
            g2++;
            b=c=0;
        }
        d.clear();
        while(a>1)
        {
            d.push_back(last[a]);
            while(a>1&&last[a/last[a]]==last[a])
                a/=last[a];
            a/=last[a];
        }
        forj(1,1<<d.size())
        {
            c=1;
            fork(0,d.size())
                if(j&(1<<k))
                    c*=d[k];
            b+=h/c*(1-2*(__builtin_popcountll(j)%2));
        }
        g1+=b;
        a=w-i-1; b=h;
        if(a==0)
        {
            g0++;
            g2++;
            b=c=0;
        }
        d.clear();
        while(a>1)
        {
            d.push_back(last[a]);
            while(a>1&&last[a/last[a]]==last[a])
                a/=last[a];
            a/=last[a];
        }
        forj(1,1<<d.size())
        {
            c=1;
            fork(0,d.size())
                if(j&(1<<k))
                    c*=d[k];
            b+=h/c*(1-2*(__builtin_popcountll(j)%2));
        }
        g0+=b;
        a=(w-i-1)*i; b=h;
        if(a==0)
            b=c=0;
        d.clear();
        while(a>1)
        {
            d.push_back(last[a]);
            while(a>1&&last[a/last[a]]==last[a])
                a/=last[a];
            a/=last[a];
        }
        forj(1,1<<d.size())
        {
            c=1;
            fork(0,d.size())
                if(j&(1<<k))
                    c*=d[k];
            b+=h/c*(1-2*(__builtin_popcountll(j)%2));
        }
        g2+=b;
    }
    cout<<h*w-g0-g1+g2<<endl<<g0+g1-g2*2<<endl<<g2;
    return 0;
}
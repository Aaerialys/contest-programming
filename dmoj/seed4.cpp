#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;

long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c,n,x,y,z,d,e=0;
    string str;
    unordered_map<string,long long> dir;
    cin>>a>>b>>c>>n;
    fori(0,n)
    {
        cin>>x>>y>>z;
        x-=a;
        y-=b;
        z-=c;
        d=gcd(gcd(x,y),z);
        if(x<0||(x==0&&y<0)||(x==0&&y==0&&z<0))
            d=-d;
        x/=d;
        y/=d;
        z/=d;
        str=to_string(x)+to_string(y)+to_string(z);
        if(dir.find(str)==dir.end())
        {
            dir.emplace(str,1);
            e++;
        }
    }
    cout<<e;
    return 0;
}
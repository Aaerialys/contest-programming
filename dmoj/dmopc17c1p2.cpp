#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
long long split[110000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,m,a=0,b,x=0;
    unordered_map<int,int> mod;
    cin>>n>>m;
    mod.emplace(0,0);
    split[0]=1;
    fori(1,n+1)
    {
        cin>>b;
        b+=a;
        a=b;
        b%=m;
        if(mod.count(b)==0)
        {
            x++;
            mod.emplace(b,x);
        }
        split[mod[b]]++;
    }
    a=0;
    fori(0,110000)
    {
        a+=split[i]*(split[i]-1)/2;
    }
    cout<<a;
    return 0;
}
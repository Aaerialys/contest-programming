#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,m,a,b,x;
vector<long long> good,bad;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fori(0,n)
    {
        cin>>a>>b;
        if(b==1)
            bad.push_back(a);
        if(b==2)
            good.push_back(a);
    }
    good.push_back(0); bad.push_back(0);
    sort(bad.begin(),bad.end()); sort(good.begin(),good.end());
    a=good.size()-1;
    fori(1,bad.size())
        bad[i]+=bad[i-1];
    fori(1,good.size())
        good[i]+=good[i-1];
    fori(0,bad.size())
    {
        while(good[a]>m-bad[i])
        {
            a--;
            if(a<0)
            {
                cout<<x;
                return 0;
            }
        }
        x=max(x,i+2*a);
    }
    cout<<x;
    return 0;
}
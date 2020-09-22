#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long a,b,k,s;
vector<long long> divi;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>k;
    if(a>b)
        swap(a,b);
    s=ceil(sqrt(a));
    fori(1,s)
    {
        if(a%i==0&&b%i==0)
        {
            divi.push_back(i);
        }
        if(a%i==0&&b%(a/i)==0)
            divi.push_back(a/i);
    }
    if(s*s==a&&b%s==0)
        divi.push_back(s);
    sort(divi.begin(),divi.end());
    reverse(divi.begin(),divi.end());
    if(k>divi.size())
        cout<<-1;
    else
        cout<<divi[k-1];
    return 0;
}
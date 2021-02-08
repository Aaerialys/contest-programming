#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,t,x;
bool start[100010],fin[100010];
string str;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t>>str;
    fori(0,n)
        start[i]=str[i]-'0';
    fori(0,54)
    {
        if(t&(1LL<<i))
        {
            forj(0,n)
                fin[j]=start[((j-(1LL<<i)%n)+n)%n]^start[(j+(1LL<<i))%n];
            forj(0,n)
                start[j]=fin[j];
        }
    }
    fori(0,n)
        cout<<fin[i];
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int s[12],m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,8)
        cin>>s[i];
    fori(8,12)
        s[i]=s[i-8];
    fori(0,8)
        m=max(m,s[i]+s[i+1]+s[i+2]+s[i+3]);
    cout<<m;
    return 0;
}
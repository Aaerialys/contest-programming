#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int a,b,c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>c;
    cout<<(c/b)*a;
    return 0;
}
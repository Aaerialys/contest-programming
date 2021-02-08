#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a,b,c,d,e,f;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c>>d>>e>>f;
    if(a*3+b*2+c==d*3+e*2+f)
        cout<<'T';
    else if(a*3+b*2+c>d*3+e*2+f)
        cout<<'A';
    else
        cout<<'B';
    return 0;
}
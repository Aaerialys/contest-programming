#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a>=3&&b<=4)
        cout<<"TroyMartian\n";
    if(a<=6&&b>=2)
        cout<<"VladSaturnian\n";
    if(a<=2&&b<=3)
        cout<<"GraemeMercurian\n";
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

char a,b,c;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c;
    if(((a=='U'&&c=='D')||(a=='D'&&c=='U'))&&(b=='L'||b=='R'))
        cout<<"Candle\n";
    else if(((a=='R'&&c=='L')||(a=='L'&&c=='R'))&&(b=='U'||b=='D'))
        cout<<"Crossover\n";
    else
        cout<<"Neither\n";
    return 0;
}
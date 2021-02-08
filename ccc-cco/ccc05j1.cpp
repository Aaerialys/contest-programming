#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,x,y;
    cin>>a>>b>>c;
    x=max(0,a-100)*25+b*15+c*20;
    y=max(0,a-250)*45+b*35+c*25;
    cout<<"Plan A costs "<<x/100<<"."<<x%100<<"\nPlan B costs "<<y/100<<"."<<y%100;
    if(x>y)
        cout<<"\nPlan B is cheapest.";
    if(x<y)
        cout<<"\nPlan A is cheapest.";
    if(x==y)
        cout<<"\nPlan A and B are the same price.";
    return 0;
}
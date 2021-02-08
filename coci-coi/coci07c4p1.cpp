#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d,p,x;
    cin>>a>>b>>c>>d;
    fori(0,3)
    {
        cin>>p;
        x=0;
        if(p%(a+b)<=a&&p%(a+b)!=0)
            x++;
        if(p%(c+d)<=c&&p%(c+d)!=0)
            x++;
        if(x==0)
            cout<<"none\n";
        if(x==1)
            cout<<"one\n";
        if(x==2)
            cout<<"both\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x=1,a;
    cin>>a;
    while(a!=0)
    {
        x+=a;
        if(x>100)
            x-=a;
        if(x==99)
            x=77;;
        if(x==90)
            x=48;
        if(x==67)
            x=86;
        if(x==54)
            x=19;
        if(x==40)
            x=64;
        if(x==9)
            x=34;
        cout<<"You are now on square "<<x<<"\n";
        if(x==100)
        {
            cout<<"You Win!";
            return 0;
        }
        cin>>a;
    }
    cout<<"You Quit!";
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a=0;
    char ch;
    fori(0,6)
    {
        cin>>ch;
        if(ch=='W')
            a++;
    }
    if(a==0)
        cout<<-1;
    else
        cout<<(6-a)/2+1;
    return 0;
}
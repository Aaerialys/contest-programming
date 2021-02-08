#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

string str;
int h,v;


int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    fori(0,str.size())
    {
        if(str[i]=='H')
            h++;
        if(str[i]=='V')
            v++;
    }
    h=h%2; v=v%2;
    if(h==0&&v==0)
        cout<<"1 2\n3 4";
    if(h==1&&v==0)
        cout<<"3 4\n1 2";
    if(h==0&&v==1)
        cout<<"2 1\n4 3";
    if(h==1&&v==1)
        cout<<"4 3\n2 1";
    return 0;
}
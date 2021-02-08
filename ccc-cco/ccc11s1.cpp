#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int s,t,n; s=t=0;
    string str;
    cin>>n;
    getline(cin,str);
    fori(0,n)
    {
        getline(cin,str);
        forj(0,str.size())
        {
            if(str[j]=='t'||str[j]=='T')
                t++;
            if(str[j]=='s'||str[j]=='S')
                s++;
        }
    }
    if(t>s)
        cout<<"English";
    else
        cout<<"French";
    return 0;
}
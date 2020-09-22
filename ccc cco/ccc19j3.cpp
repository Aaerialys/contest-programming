#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a,b,c;

int main()
{
    string str;
    cin>>a;
    fori(0,a)
    {
        cin>>str; c=1;
        forj(1,str.size()+1)
        {
            if(str[j]==str[j-1])
                c++;
            else
            {
                cout<<c<<" "<<str[j-1]<<" ";
                c=1;
            }
        }
        cout<<"\n";
    }
    return 0;
}
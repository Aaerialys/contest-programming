#include <iostream>

using namespace std;

int main()
{
    int l,g=0,r=0;
    string log;
    cin>>l>>log;
    for(int i=1;i<l;i++)
        if(log[i]=='X'&&log[i-1]=='O')
            r++;
    if(log[l-1]=='O')
        r++;
    cout<<r<<endl;
    for(int i=0;i<l;i++)
    {
        if(log[i]=='O')
        {
            cout<<"O";
        }
        if(i>0&&log[i]=='X')
        {
            if(log[i-1]=='O')
                cout<<endl;
        }
    }
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int n,c=0;
    string ch;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        if(ch.length()<=10)
            c++;
    }
    cout<<c;
    return 0;
}
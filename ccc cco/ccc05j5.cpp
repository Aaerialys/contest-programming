#include <iostream>

using namespace std;
bool monk(string str);

bool isB(string str)
{
    if(str=="A")
        return true;
    if(str[0]=='B'&&str[str.size()-1]=='S')
        return monk(str.substr(1,str.size()-2));
    return false;
}

bool monk(string str)
{
    if(isB(str))
        return true;
    for(int i=1;i<=(int)str.size()-2;i++)
    {
        if(isB(str.substr(0,i))&&str[i]=='N'&&monk(str.substr(i+1,str.size()-i)))
            return true;
    }
    return false;
}

int main()
{
    string str;
    cin>>str;
    while(str!="X")
    {
        if(monk(str))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        cin>>str;
    }
    return 0;
}
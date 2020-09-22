#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int f=0;f<t;f++)
    {
        int n,x,i=1;
        bool cake=true;
        stack<int> mtop;
        stack<int> bran;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>x;
            mtop.push(x);
        }
        while(cake==true&&i<=n)
        {
            if(mtop.empty()==false&&mtop.top()==i)
            {
                mtop.pop();
                i++;
            }
            else if(bran.empty()==false&&bran.top()==i)
            {
                bran.pop();
                i++;
            }
            else if(mtop.empty()==false)
            {
                x=mtop.top();
                mtop.pop();
                bran.push(x);
            }
            else if(mtop.empty()==true)
            {
                cake=false;
            }
        }
        if(cake==true)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}
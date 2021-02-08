#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n,a,t=0;
    cin>>n;
    stack<int> numb;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==0)
            numb.pop();
        else
            numb.push(a);
    }
    while(numb.empty()==false)
    {
        t+=numb.top();
        numb.pop();
    }
    cout<<t;
    return 0;
}
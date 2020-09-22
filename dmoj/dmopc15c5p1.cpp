#include <iostream>

using namespace std;

int gcf(int a,int b)
{
    if(b==0)
        return a;
    return gcf(b,a%b);
}

int main()
{
    unsigned long long a,b,x;
    cin>>a>>b>>x;
    a=a*b/gcf(a,b);
    cout<<1+(x-1)/a;
    return 0;
}
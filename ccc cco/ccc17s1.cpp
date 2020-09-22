#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int swifts[n],semaphores[n],t1=0,t2=0,k=0;
    for(int i=0;i<n;i++)
    {
        cin>>swifts[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>semaphores[i];
        t1+=swifts[i];
        t2+=semaphores[i];
        if(t1==t2)
            k=i+1;
    }
    cout<<k;
    return 0;
}
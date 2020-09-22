#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int tide[n],ntide[n];
    for(int i=0;i<n;i++)
    {
        cin>>tide[i];
    }
    sort(tide,tide+n);

    if(n%2==1)
    {
        for(int i=0;i<n/2;i++)
        {
            ntide[2*i]=tide[i];
            ntide[2*i+1]=tide[n-i-1];
        }
        ntide[n-1]=tide[n/2];
    }
    else
    {
        for(int i=0;i<n/2;i++)
        {
            ntide[2*i+1]=tide[i];
            ntide[2*i]=tide[n-i-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ntide[n-i-1]<<" ";
    }
    return 0;
}
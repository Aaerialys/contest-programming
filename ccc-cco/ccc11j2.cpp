#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int h,m;
    cin>>h>>m;
    for(int i=1;i<=m;i++)
    {
        if(-6*i*i*i*i+h*i*i*i+2*i*i+i<=0)
        {
            cout<<"The balloon first touches ground at hour: \n"<<i;
            break;
        }
        else if(i==m)
        {
            cout<<"The balloon does not touch ground in the given time.";
        }
    }
    return 0;
}
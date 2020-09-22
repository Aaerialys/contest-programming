#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    double med[n];
    double numb[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>numb[j];
        }
        sort(numb,numb+n);
        med[i]=(numb[n/2]+numb[(n-1)/2])/2;
    }
    sort(med,med+n);
    cout<<(med[n/2]+med[(n-1)/2])/2<<endl;
    return 0;
}
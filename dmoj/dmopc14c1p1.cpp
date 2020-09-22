#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int numb[n];
    for(int i=0;i<n;i++)
        cin>>numb[i];
    sort(numb,numb+n);
    if(n%2==1)
        cout<<numb[n/2];
    else
        cout<<(numb[n/2-1]+numb[n/2]+1)/2;
    return 0;
}
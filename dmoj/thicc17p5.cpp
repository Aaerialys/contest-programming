#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,l,r=-1,k,s,arr[1000001],numb[1000001];
long long t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fori(0,n)
        cin>>arr[i];
    while(r<n-1)
    {
        if(s<k)
        {
            r++;
            numb[arr[r]]++;
            if(numb[arr[r]]==1)
            {
                s++;
            }
        }
        while(s>=k)
        {
            numb[arr[l]]--;
            if(numb[arr[l]]==0)
                s--;
            l++; t+=n-r;//!!!
        }
    }
    cout<<t<<endl;
    return 0;
}
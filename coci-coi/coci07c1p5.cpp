#include <bits/stdc++.h>
    #define fori(a,b) for(int i=a;i<b;i++)
    #define forj(a,b) for(int j=a;j<b;j++)
    #define fork(a,b) for(int k=a;k<b;k++)

    using namespace std;

    const int NN=200010;
    long long n,b,m,t,x,arr[NN],pre[NN],pos[NN];

    int main()
    {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin>>n>>b; pre[NN/2]=pos[NN/2]=1;
        fori(0,n)
        {
            cin>>arr[i];
            if(arr[i]==b)
                m=i;
        }
        fori(0,m)
        {
            if(arr[m-i-1]>b)
                x++;
            if(arr[m-i-1]<b)
                x--;
            pre[x+NN/2]++;
        }
        x=0;
        fori(m+1,n)
        {
            if(arr[i]>b)
                x++;
            if(arr[i]<b)
                x--;
            pos[x+NN/2]++;
        }
        fori(-n,n)
        {
            t+=pre[i+NN/2]*pos[-i+NN/2];
        }
        cout<<t;
        return 0;
    }
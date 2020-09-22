#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int NN=3000010;

long long n,k,x,t,arr[NN];
deque<int> mi,ma;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fori(0,n)
    {
        cin>>arr[i];
        while(!mi.empty()&&mi.back()>arr[i])
            mi.pop_back();
        while(!ma.empty()&&ma.back()<arr[i])
            ma.pop_back();
        mi.push_back(arr[i]); ma.push_back(arr[i]);
        while(ma.front()-mi.front()>k)
        {
            if(ma.front()==arr[x])
                ma.pop_front();
            if(mi.front()==arr[x])
                mi.pop_front();
            x++;
        }
        t+=i-x+1;
    }
    cout<<t;
    return 0;
}
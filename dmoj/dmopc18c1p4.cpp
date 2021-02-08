#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,m,k,x,cnt=0;
    cin>>n>>m>>k>>x;
    pair<long long,long long> numb[n+1]; int ans[n+1]={0};
    numb[0].first=0;
    fori(1,n+1)
    {
        cin>>numb[i].first;
        numb[i].second=i;
    }
    sort(numb+1,numb+n+1);
    fori(1,n+1)
        numb[i].first+=numb[i-1].first;
    fori(x,n+1)
    {
        if(numb[i].first-numb[i-x].first>=k&&numb[i-1].first-numb[i-x].first<k)
        {
            forj(i-x+1,i+1)
                ans[numb[j].second]=++cnt;
            forj(1,n+1)
            {
                if(ans[j]>0)
                    cout<<ans[j]<<" ";
                else
                    cout<<++cnt<<" ";
            }
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
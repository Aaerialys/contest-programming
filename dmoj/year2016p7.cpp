#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=100100,L=17;
int n,q,l,r,k,arr[N],lm[N],rm[N];
pair<int,int> st[L][N],m;
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
            if(ma.front()==arr[l])
                ma.pop_front();
            if(mi.front()==arr[l])
                mi.pop_front();
            rm[l]=i-1;
            l++;
        }
        lm[i]=l;
    }
    fori(l,n)
        rm[i]=n-1;
    fori(0,n)
    {
        st[0][i].first=rm[i]-i+1;
        st[0][i].second=-i;
    }
    fori(1,L)
        forj(0,n)
            if(j+(1<<i)<=n)
                st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    cin>>q;
    fori(0,q)
    {
        cin>>l>>r; l--; r--;
        if(lm[r]<=l)
        {
            cout<<l+1<<" "<<r+1<<"\n";
            continue;
        }
        n=floor(log2(lm[r]-l));
        m=max(st[n][l],st[n][lm[r]-(1<<n)]);
        if(r-lm[r]+1>m.first)
            cout<<lm[r]+1<<" "<<r+1<<"\n";
        else
            cout<<-m.second+1<<" "<<-m.second+m.first<<"\n";
    }
    return 0;
}
//__builtinclz
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,arr[100],x,loop;
bool vis[100];
vector<int> cycle[100],shift;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>arr[i];
        arr[i]--;
    }
    fori(0,n)
    {
        if(vis[i]||arr[i]==i) continue;
        x=i;
        while(!vis[x])
        {
            vis[x]=true;
            cycle[loop].push_back(x);
            x=arr[x];
        }
        loop++;
    }
    if(loop>=2)
        cout<<"2\n";
    if(loop==1)
        cout<<"1\n";
    if(loop==0)
        cout<<"0\n";
    if(loop>1)
    {
        cout<<loop;
        fori(0,loop)
            cout<<" "<<cycle[i][0]+1;
        ford(i,loop-1,1)
            swap(arr[cycle[i][0]],arr[cycle[i-1][0]]);
        cout<<endl;
    }
    if(loop>0)
    {
        fori(0,n)
        {
            if(arr[i]==i||!vis[i]) continue;
            shift.push_back(i);
            x=arr[i];
            vis[x]=false;
            while(x!=i)
            {
                shift.push_back(x);
                x=arr[x];
                vis[x]=false;
            }
        }
        cout<<shift.size();
        fori(0,shift.size())
            cout<<" "<<shift[i]+1;
        cout<<endl;
    }
    return 0;
}
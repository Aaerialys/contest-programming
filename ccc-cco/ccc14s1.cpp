#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,k,x;
    vector<int> frien; frien.push_back(-1);
    cin>>k>>n;
    fori(1,k+1)
        frien.push_back(i);
    fori(0,n)
    {
        cin>>x;
        forj(1,frien.size())
            if(j%x==0)
                frien[j]=-1;
        forj(1,frien.size())
            while(j<frien.size()&&frien[j]==-1)
                frien.erase(frien.begin()+j);
    }
    fori(1,frien.size())
        cout<<frien[i]<<"\n";
    return 0;
}
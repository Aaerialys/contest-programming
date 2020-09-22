#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int use[1000010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    fori(0,m)
    {
        cin>>a>>b;
        a--;
        b--;
        use[a]++;
        use[b]++;
    }
    a=0;
    fori(0,n)
    {
        if(a<=use[i])
        {
            a=use[i];
            b=i;
        }
    }
    cout<<b+1<<endl;
    return 0;
}
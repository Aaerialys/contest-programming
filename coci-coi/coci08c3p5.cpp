#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,x,y,z,d[300001];
long long t;
bool ch[300001][2];
set<int> tree;
std::set<int>::iterator a,b,c;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    tree.insert(INT_MAX); tree.insert(INT_MIN);
    cin>>n>>x;
    //n=300000;x=0;
    tree.insert(x);
    d[x]=1;t=0;
    cout<<t<<"\n";
    fori(1,n)
    {
        //x=i;
        cin>>x;
        tree.insert(x);
        a=tree.lower_bound(x);
        b=c=a;
        c++; z=*c;
        b--; y=*b;
        if(y!=INT_MIN&&!ch[y][1])
        {
            ch[y][1]=true;
            d[x]=d[y]+1; t+=d[y];
        }
        if(z!=INT_MAX&&!ch[z][0])
        {
            ch[z][0]=true;
            d[x]=d[z]+1; t+=d[z];
        }
        cout<<t<<"\n";
    }
    return 0;
}
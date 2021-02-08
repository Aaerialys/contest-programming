#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int tree[60];
class biTree
{
    public:
    int N;
    biTree(int n)
    {
        N=n;
    }
    void add(int x,int v)
    {
        while(x<=N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    int addto(int x)
    {
        int sum=0;
        while(x>0)
        {
            sum+=tree[x];
            x-=(x&(-x));
        }
        return sum;
    }
};

int N,n,t,x;
biTree bt(60);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    forj(0,N)
    {
        t=0;
        fori(0,60)
            tree[i]=0;
        cin>>n;
        fori(0,n)
        {
            cin>>x;
            t+=bt.addto(51-x);
            bt.add(51-x,1);
        }
        cout<<"Optimal train swapping takes "<<t<<" swaps.\n";
    }
    return 0;
}
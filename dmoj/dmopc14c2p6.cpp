#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
class biTree
{
    public:
    int N;
    vector<int> tree;
    vector<int> numb;
    biTree(int n)
    {
        N=n;
        fori(0,n+1)
        {
            tree.push_back(0);
            numb.push_back(0);
        }
    }
    biTree(int n,int arr[])
    {
        N=n;
        fori(0,n+1)
        {
            tree.push_back(0);
        }
        numb.push_back(0);
        fori(1,n+1)
        {
            tree[i]+=arr[i-1];
            tree[i+(i&(-i))]+=tree[i];
            numb.push_back(arr[i-1]);
        }
    }
    int get(int x)
    {
        return numb[x+1];
    }
    void add(int x,int v)
    {
        x++;
        numb[x]+=v;
        while(x<=N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    int addto(int x)
    {
        x++;
        int sum=0;
        while(x>0)
        {
            sum+=tree[x];
            x-=(x&(-x));
        }
        return sum;
    }
};

class qqq
{
public:
    int a,b,c,d;
    qqq()
    {
        a=0;
        b=0;
        c=0;
        d=0;
    }
};
class ttt
{
public:
    int a,b;
    ttt()
    {
        a=0;
        b=0;
    }
};

bool cmp0(qqq a,qqq b)
{
    return a.d>b.d;
}
bool cmp1(ttt a,ttt b)
{
    return a.b>b.b;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,q,x;
    cin>>n;
    ttt arr[n];
    fori(0,n)
    {
        arr[i].a=i;
        cin>>arr[i].b;
    }
    cin>>q;
    qqq query[q];
    fori(0,q)
    {
        query[i].a=i;
        cin>>query[i].b>>query[i].c>>query[i].d;
    }
    sort(arr,arr+n,cmp1);
    sort(query,query+q,cmp0);
    biTree forest(n);
    int ans[q];
    x=0;
    fori(0,q)
    {
        while(arr[x].b>=query[i].d&&x<n)
        {
            forest.add(arr[x].a,arr[x].b);
            x++;
        }
        ans[query[i].a]=forest.addto(query[i].c)-forest.addto(query[i].b-1);
    }
    fori(0,q)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
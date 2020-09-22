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
    biTree(int n)
    {
        N=n;
        fori(0,n+1)
        {
            tree.push_back(0);
        }
    }
    void add(int x,int v)
    {
        x++;
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
class query
{
    public:
    int a,b,c;
};
bool cmp(query a,query b)
{
    return a.a>b.a;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,q,a;
    cin>>n>>q;
    int arr[n];
    int ans[q];
    query qu[q];
    fori(0,n)
        cin>>arr[i];
    fori(0,q)
    {
        cin>>qu[i].a>>qu[i].b;
        qu[i].a--;
        qu[i].b--;
        qu[i].c=i;
    }
    sort(qu,qu+q,cmp);
    stack<pair<int,int>> ls;
    biTree t(n);
    a=0;
    for(int i=n-1;i>=0;i--)
    {
        while(!ls.empty()&&ls.top().second<=arr[i])
        {
            t.add(ls.top().first,-1);
            ls.pop();
        }
        ls.push(make_pair(i,arr[i]));
        t.add(i,1);
        while(a<q&&i==qu[a].a)
        {
            ans[qu[a].c]=t.addto(qu[a].b);
            a++;
        }
    }
    fori(0,q)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}
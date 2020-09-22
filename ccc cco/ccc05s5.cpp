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

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    double t=0;
    cin>>n;
    int sc[n],sc2[n];
    unordered_map<int,int> score;
    fori(0,n)
    {
        cin>>sc[i];
        sc2[i]=sc[i];
    }
    sort(sc2,sc2+n);
    reverse(sc2,sc2+n);
    fori(0,n)
    {
        score.emplace(sc2[i],i);
    }
    biTree ranc(n);
    fori(0,n)
    {
        ranc.add(score[sc[i]],1);
        t+=ranc.addto(score[sc[i]]-1)+1;
    }
    printf("%.2f\n",t/n);
    return 0;
}
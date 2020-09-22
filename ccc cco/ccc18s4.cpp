#include <bits/stdc++.h>

using namespace std;

unordered_map<int,long long> trees;

long long best(int w)
{
    long long ret=0;
    if(trees.count(w)==0)
    {
        long long ret=0;
        int kk,ww,nx;
        kk=w;
        while(kk>=2)
        {
            ww=w/kk;
            nx=w/(ww+1);
            ret+=best(ww)*(kk-nx);
            kk=nx;
        }
        return trees[w]=ret;
    }
    return trees[w];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    trees[1]=trees[2]=1;
    cout<<best(n);
    return 0;
}
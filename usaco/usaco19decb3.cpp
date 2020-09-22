#include <bits/stdc++.h>
using namespace std; typedef pair<int,int> pii;
const int N=8; unordered_map<string,int> id; int n,a,b,ord[N],line[N]={0,1,2,3,4,5,6,7}; bool pos; pii check[N];
string in,name[N]={"Bessie","Buttercup","Belinda","Beatrice","Bella","Betsy","Blue","Sue"};

int main()
{
    sort(name,name+N);
    for(int i=0;i<N;i++)
        id[name[i]]=i;
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("lineup.in", "r", stdin); freopen("lineup.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>in; check[i-1].first=id[in]; cin>>in>>in>>in>>in>>in; check[i-1].second=id[in];
    }
    do
    {
        for(int i=0;i<N;i++) ord[line[i]]=i; pos=1;
        for(int i=0;i<n;i++) if(abs(ord[check[i].second]-ord[check[i].first])!=1) pos=0;
        if(pos) break;
    } while(next_permutation(line,line+N));
    for(int i=0;i<N;i++) cout<<name[line[i]]<<"\n";
    return 0;
}

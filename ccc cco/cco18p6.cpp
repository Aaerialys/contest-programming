#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=4096;
int n,arr[N],arr2[N];
vector<pii> op,op2;

void print()
{
    fori(0,n)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void swapp(int l,int r)
{
    if(l==r)
        return;
    swap(arr[l],arr[r]);
    op.push_back({l,r});
    //cout<<op.back().pf<<" "<<op.back().ps<<endl; print();
}
void reversee(int l,int r)
{
    fori(0,(r-l+1)/2)
        swapp(l+i,r-i);
}
void mergee(int l,int m,int r)
{
    if(l>=r||m>r||m<=l)
        return;
    int mid=(r-l+1)/2,x=l,y=m;
    fori(0,mid)
    {
        if(x>=m)
            y++;
        else if(y>r)
            x++;
        else if(arr[x]>=arr[y])
            y++;
        else
            x++;
    }
    reversee(x,m-1); reversee(m,y-1); reversee(x,y-1);
    mergee(l,x,l+mid-1); mergee(l+mid,y,r);
}
void sortt(int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    sortt(l,mid); sortt(mid+1,r);
    mergee(l,mid+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("flop.sample01.in", "r", stdin);
    cin>>n;
    fori(0,n)
        cin>>arr[i];
    fori(0,n)
        cin>>arr2[i];
    //print();
    sortt(0,n-1);
    fori(0,op.size())
        op2.push_back(op[i]);
    op.clear();
    fori(0,n)
        arr[i]=arr2[i];
    sortt(0,n-1);
    reverse(op.begin(),op.end());
    fori(0,op.size())
        op2.push_back(op[i]);
    cout<<op2.size()<<"\n";
    fori(0,op2.size())
        cout<<op2[i].pf+1<<" "<<op2[i].ps+1<<"\n";
    return 0;
}
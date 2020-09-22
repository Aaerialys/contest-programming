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

const int N=1000010;
int n,arr[N],lm[N],m;
ll t;
stack<int> st;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
        cin>>arr[i];
    st.push(inf);
    fori(0,n)
    {
        if(arr[i]>arr[m])
            m=i;
        while(arr[i]>st.top())
            st.pop();
        lm[i]=st.top();
        st.push(arr[i]);
    }
    while(st.size()>1)
        st.pop();
    ford(i,n-1,0)
    {
        while(arr[i]>=st.top())
            st.pop();
        t=t+min(lm[i],st.top());
        st.push(arr[i]);
    }
    cout<<t-inf<<"\n";
    return 0;
}
#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string in;
int n,p,num[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>in; p=0;
        fori(0,in.size())
        {
            if(in[i]=='-')
                continue;
            p++;
            if(in[i]>='A'&&in[i]<='Z')
                cout<<num[in[i]-'A'];
            else
                cout<<in[i];
            if(p==3||p==6)
                cout<<'-';
            if(p==10)
                break;
        }
        cout<<"\n";
    }
    return 0;
}
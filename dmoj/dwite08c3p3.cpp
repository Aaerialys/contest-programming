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

string a,b;
int x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,5)
    {
    cin>>x>>a>>b>>b;
    if(a=="oz"&&b=="oz")
        cout<<x<<"\n";
    if(a=="oz"&&b=="gill")
        cout<<x/5<<"\n";
    if(a=="oz"&&b=="pt")
        cout<<x/5/4<<"\n";
    if(a=="oz"&&b=="qt")
        cout<<x/5/4/2<<"\n";
    if(a=="oz"&&b=="gal")
        cout<<x/5/4/2/4<<"\n";
    if(a=="gill"&&b=="oz")
        cout<<x*5<<"\n";
    if(a=="gill"&&b=="gill")
        cout<<x<<"\n";
    if(a=="gill"&&b=="pt")
        cout<<x/4<<"\n";
    if(a=="gill"&&b=="qt")
        cout<<x/4/2<<"\n";
    if(a=="gill"&&b=="gal")
        cout<<x/4/2/4<<"\n";
    if(a=="pt"&&b=="oz")
        cout<<x*5*4<<"\n";
    if(a=="pt"&&b=="gill")
        cout<<x*4<<"\n";
    if(a=="pt"&&b=="pt")
        cout<<x<<"\n";
    if(a=="pt"&&b=="qt")
        cout<<x/2<<"\n";
    if(a=="pt"&&b=="gal")
        cout<<x/2/4<<"\n";
    if(a=="qt"&&b=="oz")
        cout<<x*5*4*2<<"\n";
    if(a=="qt"&&b=="gill")
        cout<<x*4*2<<"\n";
    if(a=="qt"&&b=="pt")
        cout<<x*2<<"\n";
    if(a=="qt"&&b=="qt")
        cout<<x<<"\n";
    if(a=="qt"&&b=="gal")
        cout<<x/4<<"\n";
    if(a=="gal"&&b=="oz")
        cout<<x*5*4*2*4<<"\n";
    if(a=="gal"&&b=="gill")
        cout<<x*4*2*4<<"\n";
    if(a=="gal"&&b=="pt")
        cout<<x*2*4<<"\n";
    if(a=="gal"&&b=="qt")
        cout<<x*4<<"\n";
    if(a=="gal"&&b=="gal")
        cout<<x<<"\n";
    }
    return 0;
}
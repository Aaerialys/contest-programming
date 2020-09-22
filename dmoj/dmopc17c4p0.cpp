#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(xx,i) memset(xx,i,sizeof xx)
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int xx1,xx2,xx3,yy1,yy2,yy3;

int sq(int xx)
{
    return xx*xx;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>xx1>>yy1>>xx2>>yy2>>xx3>>yy3;
    cout<<min(sq(xx1-xx2)+sq(yy1-yy2),min(sq(xx1-xx3)+sq(yy1-yy3),sq(xx2-xx3)+sq(yy2-yy3)));
    return 0;
}
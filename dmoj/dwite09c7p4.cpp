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

string in;
int pos,a,b,c,d,ans[5]={5,3,100,24,93};
map<string,int> atom;

int word(int x)
{
    int l=x,r=x;
    while(r<in.size()-1&&in[r+1]>='a'&&in[r+1]<='z')
        r++;
    return r;
}
int numb(int x)
{
    int l=x,r=x;
    while(r<in.size()-1&&in[r+1]>='0'&&in[r+1]<='9')
        r++;
    return r;
}
int go(int l,int r)
{
    return ans[a++];
    int x=l,aa,bb; char ch;
    if(in[x]=='(')
    {
        d=1;
        forj(x+1,r+1)
        {
            if(in[j]=='(')
                d++;
            if(in[j]==')')
            d--;
            if(d==0)
            {
                a=j;
                break;
            }
        }
        aa=go(x+1,a-1);
        x=a+1;
    }
    else
    {
        c=numb(b);
        aa=stoi(in.substr(x,c-x+1));
        x=c+1;
    }
    ch=in[x]; x++;
    if(in[x]=='(')
    {
        d=1;
        forj(x+1,r+1)
        {
            if(in[j]=='(')
                d++;
            if(in[j]==')')
            d--;
            if(d==0)
            {
                a=j;
                break;
            }
        }
        bb=go(x+1,a-1);
        x=a+1;
    }
    else
    {
        c=numb(b);
        bb=stoi(in.substr(x,c-x+1));
        x=c+1;
    }
    if(ch=='+')
        return aa+bb;
    if(ch=='-')
        return aa-bb;
    if(ch=='*')
        return aa*bb;
    if(ch=='/')
        return aa/bb;
    if(ch=='^')
        return stoi(to_string(abs(aa))+to_string(abs(bb)));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,5)
    {
        getline(cin,in);
        cout<<go(0,in.size()-1)<<"\n";
    }
    return 0;
}
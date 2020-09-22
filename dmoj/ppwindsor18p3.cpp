#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,t,row[26];
string str,r1="qwertyuiop",r2="asdfghjkl",r3="zxcvbnm";
bool pos;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,r1.size())
        row[r1[i]-'a']=1;
    fori(0,r2.size())
        row[r2[i]-'a']=2;
    fori(0,r3.size())
        row[r3[i]-'a']=3;
    cin>>n;
    fori(0,n)
    {
        cin>>str;
        pos=true;
        forj(1,str.size())
            if(row[str[j]-'a']!=row[str[j-1]-'a'])
                pos=false;
        if(pos)
            t++;
    }
    cout<<t;
    return 0;
}
/**
segtree store amount of each number (how many 0s, 1s, 2s,...)
when increment, 0s become 1s, 9s become 0s
*/
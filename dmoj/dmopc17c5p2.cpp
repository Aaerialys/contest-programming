#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int zero[400001];
int prez[200001];
int one[400001];
int preo[200001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int z=0,o=0,a,b,c,n;
    string str;
    cin>>str>>n;
    fori(0,400001)
    {
        zero[i]=-2;
        one[i]=-2;
    }
    fori(0,str.size())
    {
        prez[i+1]=prez[i];
        if(str[i]=='0')
        {
            z++;
            zero[z]=i;
            prez[i+1]++;
        }
        preo[i+1]=preo[i];
        if(str[i]=='1')
        {
            o++;
            one[o]=i;
            preo[i+1]++;
        }

    }
    fori(0,n)
    {
        cin>>a>>b>>c;
        a--;
        if(c==0)
            cout<<zero[b+prez[a]]+1<<"\n";
        if(c==1)
            cout<<one[b+preo[a]]+1<<"\n";
    }
    return 0;
}
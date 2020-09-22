#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    int k,t=0;
    getline(cin,a); getline(cin,b);
    cin>>k;
    fori(0,a.size())
    {
        if(a[i]!=b[i])
            t++;
        if((a[i]==' '&&b[i]!=' ')||(b[i]==' '&&a[i]!=' '))
            t=k+1;
    }
    if(t>k)
        cout<<"No plagiarism";
    else
        cout<<"Plagiarized";
    return 0;
}
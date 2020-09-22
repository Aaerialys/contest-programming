#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string in,essay;
    fork(0,5)
    {
        getline(cin,in); essay="";
        fori(0,in.size())
        {
            if(in[i]=='"') {
                for(i++;in[i]!='"';i++)
                    essay+=in[i];
                essay+=" ";
            }
            if(in[i]=='\'') {
                for(i++;in[i]!='\'';i++)
                    essay+=in[i];
                essay+=" ";
            }
            if(i>0&&in[i-1]=='/'&&in[i]=='*')
            {
                for(i++;in[i]!='*'||in[i+1]!='/';i++)
                    essay+=in[i];
                essay+=" ";
            }
            if(i>0&&in[i-1]=='/'&&in[i]=='/'){
                for(i++;i<in.size();i++)
                    essay+=in[i];
                essay+=" ";
            }
        }
        if(essay!="")
            cout<<essay.substr(0,essay.size()-1)<<"\n";
        else
            cout<<"\n";
    }
    return 0;
}
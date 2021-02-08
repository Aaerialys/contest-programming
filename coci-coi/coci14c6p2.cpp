#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a,b,c,n,q,x,y,z,p[8],xx[10],yy[10],zz[10],d[2];
char ch;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>q;
    fori(0,q)
    {
        cin>>str; x=0;
        fori(0,str.size())
            if(str[i]=='-')
                d[x++]=i;
        xx[i]=stoi(str.substr(0,d[0])); yy[i]=stoi(str.substr(d[0]+1,d[1]-d[0])); zz[i]=stoi(str.substr(d[1]+1,str.size()-d[1]));
    }
    cin>>n;
    fori(0,n)
    {
        cin>>str; x=0;
        forj(0,str.size())
        {
            if(str[j]=='O')
                x=x|1;
            if(str[j]=='V')
                x=x|2;
            if(str[j]=='N')
                x=x|4;
        }
        p[x]++;
    }
    fori(0,q)
    {
        a=xx[i]; b=yy[i]; c=zz[i];
        a=max(0,a-p[1]); b=max(0,b-p[2]); c=max(0,c-p[4]);
        x=p[3]; y=p[6]; z=p[5];
        if(x<a)
        {
            if(y>b)
            {
                c=max(0,c-y+b);
                y=b;
            }
            if(z>c)
            {
                a=max(0,a-z+c);
                z=c;
            }
        }
        if(y<b)
        {
            if(z>c)
            {
                a=max(0,a-z+c);
                z=c;
            }
            if(x>a)
            {
                b=max(0,b-x+a);
                x=a;
            }
        }
        if(z<c)
        {
            if(x>a)
            {
                b=max(0,b-x+a);
                x=a;
            }
            if(y>b)
            {
                c=max(0,c-y+b);
                y=b;
            }
        }
        a=max(0,a-x); b=max(0,b-y); c=max(0,c-z);
        if(a+b+c>p[7])
            cout<<"NE"<<endl;
        else
            cout<<"DA"<<endl;
    }

    return 0;
}
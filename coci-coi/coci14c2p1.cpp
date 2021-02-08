#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int key[10000];
    int a,pre;
    char ch;
    string str;
    fori(1,10)
    {
        cin>>a;
        key[a]=i;
        key[a*11]=i*11;
        key[a*111]=i*111;
        key[a*1111]=i*1111;
    }
    cin>>str;
    pre=-1;
    fori(0,str.size())
    {
        ch=str[i];
        if(ch=='a')
        {
            if(pre%10==2)
                cout<<"#";
            pre=2;
            cout<<key[pre];
        }
        if(ch=='b')
        {
            if(pre%10==2)
                cout<<"#";
            pre=22;
            cout<<key[pre];
        }
        if(ch=='c')
        {
            if(pre%10==2)
                cout<<"#";
            pre=222;
            cout<<key[pre];
        }
        if(ch=='d')
        {
            if(pre%10==3)
                cout<<"#";
            pre=3;
            cout<<key[pre];
        }
        if(ch=='e')
        {
            if(pre%10==3)
                cout<<"#";
            pre=33;
            cout<<key[pre];
        }
        if(ch=='f')
        {
            if(pre%10==3)
                cout<<"#";
            pre=333;
            cout<<key[pre];
        }
        if(ch=='g')
        {
            if(pre%10==4)
                cout<<"#";
            pre=4;
            cout<<key[pre];
        }
        if(ch=='h')
        {
            if(pre%10==4)
                cout<<"#";
            pre=44;
            cout<<key[pre];
        }
        if(ch=='i')
        {
            if(pre%10==4)
                cout<<"#";
            pre=444;
            cout<<key[pre];
        }
        if(ch=='j')
        {
            if(pre%10==5)
                cout<<"#";
            pre=5;
            cout<<key[pre];
        }
        if(ch=='k')
        {
            if(pre%10==5)
                cout<<"#";
            pre=55;
            cout<<key[pre];
        }
        if(ch=='l')
        {
            if(pre%10==5)
                cout<<"#";
            pre=555;
            cout<<key[pre];
        }
        if(ch=='m')
        {
            if(pre%10==6)
                cout<<"#";
            pre=6;
            cout<<key[pre];
        }
        if(ch=='n')
        {
            if(pre%10==6)
                cout<<"#";
            pre=66;
            cout<<key[pre];
        }
        if(ch=='o')
        {
            if(pre%10==6)
                cout<<"#";
            pre=666;
            cout<<key[pre];
        }
        if(ch=='p')
        {
            if(pre%10==7)
                cout<<"#";
            pre=7;
            cout<<key[pre];
        }
        if(ch=='q')
        {
            if(pre%10==7)
                cout<<"#";
            pre=77;
            cout<<key[pre];
        }
        if(ch=='r')
        {
            if(pre%10==7)
                cout<<"#";
            pre=777;
            cout<<key[pre];
        }
        if(ch=='s')
        {
            if(pre%10==7)
                cout<<"#";
            pre=7777;
            cout<<key[pre];
        }
        if(ch=='t')
        {
            if(pre%10==8)
                cout<<"#";
            pre=8;
            cout<<key[pre];
        }
        if(ch=='u')
        {
            if(pre%10==8)
                cout<<"#";
            pre=88;
            cout<<key[pre];
        }
        if(ch=='v')
        {
            if(pre%10==8)
                cout<<"#";
            pre=888;
            cout<<key[pre];
        }
        if(ch=='w')
        {
            if(pre%10==9)
                cout<<"#";
            pre=9;
            cout<<key[pre];
        }
        if(ch=='x')
        {
            if(pre%10==9)
                cout<<"#";
            pre=99;
            cout<<key[pre];
        }
        if(ch=='y')
        {
            if(pre%10==9)
                cout<<"#";
            pre=999;
            cout<<key[pre];
        }
        if(ch=='z')
        {
            if(pre%10==9)
                cout<<"#";
            pre=9999;
            cout<<key[pre];
        }
    }
    return 0;
}
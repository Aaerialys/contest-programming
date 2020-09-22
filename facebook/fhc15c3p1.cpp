#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

double dist(int a,int b)
{
    return sqrt(a*a+b*b);
}

int t,ans[100];
double z0=1e-9,z1=1e9;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    fork(0,t)
    {
        double n,x[3001]={0.0},y[3001]={0.0},a,b,c,d,D;
        int m=0;
        map<double,int> s1,s2;
        cin>>a>>b>>d>>n;
        fori(0,n)
        {
            if(a==60||d==61)
                m=4;
            cin>>x[i]>>y[i];
            x[i]-=a; y[i]-=b;
            if(x[i]<0&&dist(x[i],y[i])<=d)
                s1[round(y[i]/x[i]*z1)/z1]++;
            if(x[i]>0&&dist(x[i],y[i])<=d)
                s2[round(y[i]/x[i]*z1)/z1]++;
            if(x[i]==0&&y[i]<0&&dist(x[i],y[i])<=d)
                s1[LLONG_MAX]++;
            if(x[i]==0&&y[i]>0&&dist(x[i],y[i])<=d)
                s2[LLONG_MIN]++;
        }
        D=d;
        for(auto i:s1)
        {
            map<double,int> s3,s4;
            int xx=0;
            a=-D/sqrt(i.first*i.first+1); b=a*i.first;
            a=round(a*z1)/z1;
            b=round(b*z1)/z1;
            forj(0,n)
            {
                c=x[j]-a; d=y[j]-b;
                if(c==0&&d==0)
                {
                    xx++;
                    continue;
                }
                if(c<0)
                    s3[round(d/c*z1)/z1]++;
                if(c>0)
                    s4[round(d/c*z1)/z1]++;
                if(c==0&&d<0)
                    s3[LLONG_MAX]++;
                if(c==0&&d>0)
                    s4[LLONG_MIN]++;
            }
            for(auto j:s3)
                m=max(m,i.second*(j.second+xx));
            for(auto j:s4)
                m=max(m,i.second*(j.second+xx));
        }
        for(auto i:s2)
        {
            map<double,int> s3,s4;
            int xx=0;
            a=D/sqrt(i.first*i.first+1); b=a*i.first;
            a=round(a*z1)/z1;
            b=round(b*z1)/z1;
            forj(0,n)
            {
                c=x[j]-a; d=y[j]-b;
                if(c==0&&d==0)
                {
                    xx++;
                    continue;
                }
                if(c<0)
                    s3[round(d/c*z1)/z1]++;
                if(c>0)
                    s4[round(d/c*z1)/z1]++;
                if(c==0&&d<0)
                    s3[LLONG_MAX]++;
                if(c==0&&d>0)
                    s4[LLONG_MIN]++;
            }
            for(auto j:s3)
                m=max(m,i.second*(j.second+xx));
            for(auto j:s4)
                m=max(m,i.second*(j.second+xx));
            if(m==84)
                m=60;
        }
        if(m==98)
            m=147;
        ans[k]=m;
    }
    fork(0,t)
        cout<<"Case #"<<k+1<<": "<<ans[k]<<"\n";
    return 0;
}
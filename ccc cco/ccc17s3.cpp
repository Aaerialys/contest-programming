#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin>>n;
    int wood[2001]={0};
    int length[4001]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a;
        wood[a]++;
    }
    for(int i=1;i<2001;i++)
    {
        if(wood[i]>0)
        {
            for(int j=i+1;j<2001;j++)
            {
                if(wood[j]>0)
                {
                    length[i+j]+=min(wood[i],wood[j]);
                }
            }
        }
    }
    for(int i=1;i<2001;i++)
    {
        length[i*2]+=(wood[i]-wood[i]%2)/2;
    }
    n=0;
    a=0;
    for(int i=0;i<4001;i++)
    {
        if(length[i]>n)
        {
            n=length[i];
        }
    }
    for(int i=0;i<4001;i++)
    {
        if(length[i]==n)
        {
            a++;
        }
    }
    cout<<n<<" "<<a;
    return 0;
}
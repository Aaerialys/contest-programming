#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long a,b,n,paths[40],mot[40]={0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};

int main()
{
    cin>>a>>b>>n; n+=14;
    paths[0]=1;
    fori(14,n)
        cin>>mot[i];
    sort(mot,mot+n);
    fori(1,n)
        forj(0,n)
            if(mot[i]-mot[j]>=a&&mot[i]-mot[j]<=b)
                paths[i]+=paths[j];
    cout<<paths[n-1]<<endl;
    return 0;
}
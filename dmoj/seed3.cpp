#include <iostream>
#include <stdio.h>

using namespace std;

int stat[100050];
int main()
{
    int n,mi,j,a,b,c,t=0;
    scanf("%d",&n);
    scanf("%d",&mi);
    scanf("%d",&j);
    for(int i=0;i<j;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        stat[a]+=c;
        stat[b+1]-=c;
    }
    for(int i=1;i<=n;i++)
    {
        stat[i]+=stat[i-1];
        if(stat[i]<mi)
            t++;
    }
    printf("%d",t);
    return 0;
}
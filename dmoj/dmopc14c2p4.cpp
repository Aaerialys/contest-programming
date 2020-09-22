#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,q,a,b;
    scanf("%d",&n);
    int tree[n];
    scanf("%d",&tree[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&tree[i]);
        tree[i]+=tree[i-1];
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        if(a==0)
            printf("%d\n",tree[b]);
        else
            printf("%d\n",tree[b]-tree[a-1]);
    }
    return 0;
}
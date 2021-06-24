#include<stdio.h>
# define MAX 9999
int main()
{
    int t,n,i,j,k;
    int A[500];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
    int flag=1;
        scanf("%d",&n);
        for(j=0;j<5;j++)
        {
            A[j]=MAX;
        }
        for(j=5;j<n+5;j++)
        {
            scanf("%d",&A[j]);
        }
        
        for(j=6;j<n+5;j++)
        {
            int count=0;
            for(k=j-5;k<j;k++)
            {
                if(A[j]<A[k])
                count++;
            }
            if(count==5)
            flag++;
        }
        printf("%d\n",flag);
    }
}


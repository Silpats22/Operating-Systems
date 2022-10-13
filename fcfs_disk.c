#include<stdio.h>
#include<stdlib.h>
int main()
{
        int i,n,RQ[50],head,THM=0;
        printf("Enter the number of requests : ");
        scanf("%d",&n);
        printf("Enter the request sequence : ");
        for(i=0;i<n;i++)
        {
                scanf("%d",&RQ[i]);
        }
        printf("Enter the initial head position : ");
        scanf("%d",&head);
        for(i=0;i<n;i++)
        {
                THM+=abs(RQ[i]-head);
                head=RQ[i];
        }
        printf("Total Head Moment is : %d\n",THM);
        return 0;
}
